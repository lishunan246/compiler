#include "symbol_table.h"

const int ERROR_RETURN = 0xffff;
int currentNestLevel = 0;

// **** define symbols of var, type, func and proc
// symbol map of var and const
static std::map<std::string, VariableList> variableMap;

// symbol map of type define
static std::map<std::string, TypeList> typeMap;

// symbol maps of func and proc
static std::map<std::string, FuncList> funcMap;
static std::map<std::string, ProcList> procMap;

static int totalOffset[50];


void printSymbolTable() {
    printf("Symbol table --->>>\n>>>-------------------------------------\n");
    printf("TTType\tname\tnest\tmem\tlineno\n");
    
    std::map<std::string, VariableList>::iterator itor1;
    for (itor1 = variableMap.begin(); itor1 != variableMap.end(); itor1++) {
        VariableList l = itor1->second;
        while(l != NULL) {
            LineList t = l->lines;
            printf("%s\t", l->isConst ? "const" : "var");
            printf("%s\t", l->name);
            printf("%d\t", l->nestLevel);
            printf("%d\t", l->memloc.offset);
            while (t) {
                printf("%d\t", t->lineno);
                t = t->next;
            }
            printf("\n");
            l = l->next;
        }
    }
    
    printf("TTType\tname\tnest\tret\tpara\n");
    std::map<std::string, FuncList>::iterator itor;
    for (itor = funcMap.begin(); itor != funcMap.end(); itor++) {
        FuncList l = itor->second;
        SimpleTypeList t = l->paraList;
        printf("func\t");
        printf("%s\t", l->name);
        printf("%d\t", l->nestLevel);
        printf("%d\t", l->retType);
        while(t) {
            printf("%s\t", t->name);
            t = t->next;
        }
        printf("\n");
    }
}

SubBoundDef newSubBoundDef(ExpType type, void* lower, void* upper) {
	SubBoundDef p = (SubBoundDef) malloc(sizeof(struct SubBoundDefRec));
	p->boundType = type;
	if(type == EXPTYPE_INT) {
		p->LowerBound.i = *(int*)lower;
		p->UpperBound.i = *(int*)upper;
	} else if(type == EXPTYPE_CHAR) {
		p->LowerBound.c = *(char*)lower;
		p->UpperBound.c = *(char*)upper;
	} else if(type == EXPTYPE_SIMPLE_ENUM) {
		p->LowerBound.m = (char*)lower;
		p->UpperBound.m = (char*)upper;
	}
	return p;
}

ArrayDef newArrayDef(ExpType arrayType, ExpType boundType, void* lower, void* upper) {
	ArrayDef p = (ArrayDef) malloc(sizeof(struct ArrayDefRec));
	p->arrayType = arrayType;
	p->subBound = newSubBoundDef(boundType, lower, upper);
	return p;
}

EnumDef newEnumDef(char* mark) {
	EnumDef p = (EnumDef) malloc(sizeof(struct EnumDefRec));
	p->mark = mark;
	p->next = NULL;

	return p;
}

EnumDef insertEnumDef(EnumDef enumList, char* mark) {
	while(enumList->next != NULL)
		enumList = enumList->next;
	enumList->next = newEnumDef(mark);

	return enumList->next;
}

TypeList newTypeDef(char* name, ExpType type, int nestLevel, void* pAttr, int size) {
	TypeList p = (TypeList) malloc(sizeof(struct TypeListRec));
	p->name = name;
	p->type = type;
	p->nestLevel = nestLevel;
	p->pAttr = pAttr;
	p->size = size;
	p->next = NULL;

	return p;
}

TypeList insertTypeDef(TypeList typeList, char* name, ExpType type, int nestLevel, void* pAttr, int size) {
	while(typeList->next != NULL)
		typeList = typeList->next;
	typeList->next = newTypeDef(name, type, nestLevel, pAttr, size);

	return typeList->next;
}

RecordDef newDefinedRecord(TypeList ptr) {
	RecordDef p = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	p->type = DEFINED;
	p->ptr.pDef = ptr;
	p->next = NULL;

	return p;
}

RecordDef newAnonyRecord(TypeList typeList) {
	RecordDef p = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	p->type = UNDEFINED;
	p->ptr.pAnony = typeList;
	p->next = NULL;

	return p;
}

SimpleTypeList newSimpleTypeList(char* name, ExpType type, int isVar) {
	SimpleTypeList p = (SimpleTypeList) malloc(sizeof(struct SimpleTypeListRec));
	p->name = name;
	p->type = type;
	p->isVar = isVar;

	return p;
}

SimpleTypeList insertSimpleTypeList(SimpleTypeList simpleList, char* name, ExpType type, int isVar) {
	while(simpleList->next != NULL)
		simpleList = simpleList->next;
	simpleList->next = newSimpleTypeList(name, type, isVar);

	return simpleList->next;
}

int procListInsert(TreeNode* procHead) {

	char* name = procHead->attr.name;
	int nestLevel = currentNestLevel;
	int paraNestLevel = nestLevel + 1;
	int offset = 4;

	SimpleTypeList paraList;
	SimpleTypeList tmpList;
	TreeNode* tmpNode;

	if(procHead->child[0] == NULL)
		paraList = NULL;
	else {
	   	if(procHead->child[0]->kind.decl == DECL_VAR_PARA) {
			paraList = newSimpleTypeList(procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, true);
		} else {
			paraList = newSimpleTypeList(procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, false);
		}

		varListInsert(procHead->child[0]->child[0]->attr.name, procHead->child[0]->child[1]->type, false, paraNestLevel, NULL, procHead->lineno, 0, offset);
		offset = offset + OFFSET_INC;

		tmpNode = procHead->child[0]->sibling;
		tmpList = paraList;
		while(tmpNode != NULL) {
			if(tmpNode->kind.decl == DECL_VAR_PARA)
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, true);
			else
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, false);

			varListInsert(tmpNode->child[0]->attr.name, tmpNode->child[1]->type, false, paraNestLevel, NULL, tmpNode->lineno, 0, offset);
			offset = offset + OFFSET_INC;

			tmpNode = tmpNode->sibling;
		}
	}

    ProcList tmpProc = (ProcList)malloc(sizeof(struct ProcListRec));
    tmpProc->name = name;
    tmpProc->paraList = paraList;
    tmpProc->nestLevel = nestLevel;
    tmpProc->next = NULL;
    procMap[std::string(name)] = tmpProc;

	return offset;
}

int funcListInsert(TreeNode* funcHead) {

	char* name = funcHead->attr.name;
	int nestLevel = currentNestLevel;
	int paraNestLevel = nestLevel + 1;
	int offset = 4;

	ExpType retType = funcHead->child[1]->type;
	SimpleTypeList paraList;
	SimpleTypeList tmpList;
	TreeNode* tmpNode;


	if(funcHead->child[0] == NULL)
		paraList = NULL;
	else {
	   	if(funcHead->child[0]->kind.decl == DECL_VAR_PARA) {
			paraList = newSimpleTypeList(funcHead->child[0]->child[0]->attr.name, funcHead->child[0]->child[1]->type, true);
		} else {
			paraList = newSimpleTypeList(funcHead->child[0]->child[0]->attr.name, funcHead->child[0]->child[1]->type, false);
		}
		varListInsert(funcHead->child[0]->child[0]->attr.name,funcHead->child[0]->child[1]->type, false, paraNestLevel, NULL, funcHead->lineno, 0, offset);
		offset = offset + OFFSET_INC;

		tmpNode = funcHead->child[0]->sibling;
		tmpList = paraList;
		while(tmpNode != NULL) {
			if(tmpNode->kind.decl == DECL_VAR_PARA)
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, true);
			else
				tmpList = insertSimpleTypeList(tmpList, tmpNode->child[0]->attr.name, tmpNode->child[1]->type, false);

			varListInsert(tmpNode->child[0]->attr.name, tmpNode->child[1]->type, false, paraNestLevel, NULL, tmpNode->lineno, 0, offset);
			offset = offset + OFFSET_INC;

			tmpNode = tmpNode->sibling;
		}
	}

	varListInsert(funcHead->attr.name, retType, false, paraNestLevel, NULL, funcHead->lineno, 0, offset);
	offset = offset + OFFSET_INC;

    FuncList tmpFunc = (FuncList) malloc(sizeof(struct FuncListRec));
    tmpFunc->name = name;
    tmpFunc->paraList = paraList;
    tmpFunc->retType = retType;
    tmpFunc->nestLevel = nestLevel;
    tmpFunc->next = NULL;
    funcMap[std::string(name)] = tmpFunc;

	return offset;
}

void typeListAliaseInsert(char* name, char* aliase) {
    if (typeMap.count(std::string(name)) > 0) {
        typeMap[std::string(name)]->aliaseSet->aliase = aliase;
    } else {
        std::cout << "Type doesn't exist" << std::endl;
    }
}

void typeListInsert(char* name, ExpType type, int nestLevel,
                    void* pAttr, int size) {
    TypeList tmpType = (TypeList)malloc(sizeof(struct TypeListRec));
    tmpType->name = name;
    tmpType->aliaseSet = NULL;
    tmpType->type = type;
    tmpType->nestLevel = nestLevel;
    tmpType->pAttr = pAttr;
    tmpType->size = size;
    tmpType->next = NULL;
    typeMap[std::string(name)] = tmpType;
}

void varListInsert(char* name, ExpType type, int isConst, int nestLevel,
                   void* pAttr, int lineno, int baseLoc, int offset) {
    VariableList l = (variableMap.count(std::string(name)) > 0)
        ? variableMap[std::string(name)] : NULL;
    VariableList tmp = l;
    if(tmp == NULL || nestLevel > tmp->nestLevel) {
        tmp = (VariableList) malloc(sizeof(struct VariableListRec));
        tmp->name = name;
        tmp->type = type;
        tmp->isConst = isConst;
        tmp->nestLevel = nestLevel;
        tmp->pAttr = pAttr;
        tmp->lines = (LineList) malloc(sizeof(struct LineListRec));
        tmp->lines->lineno = lineno;
        tmp->lines->next = NULL;
        tmp->memloc.baseLoc = baseLoc;
        tmp->memloc.offset = offset;
        tmp->next = l;
        variableMap[std::string(name)] = tmp;
    } else {
        LineList t = tmp->lines;
        while(t->next != NULL)
            t = t->next;
        t->next = (LineList) malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
}

VariableList findVarList(char* name) {
    if (variableMap.find(std::string(name)) != variableMap.end()) {
        VariableList tmp = variableMap[std::string(name)];
        tmp->memloc.baseLoc = currentNestLevel - tmp->nestLevel;
        return tmp;
    }
    return NULL;
}

FuncList findFuncList(char* name) {
    if (funcMap.count(std::string(name)) > 0) {
        return funcMap[std::string(name)];
    }
    return NULL;
}

ProcList findProcList(char* name) {
    if (procMap.count(std::string(name)) > 0) {
        return procMap[std::string(name)];
    }
    return NULL;
}

TypeList findTypeList(char* name) {
    if (typeMap.count(std::string(name)) > 0) {
        return typeMap[std::string(name)];
    }
    return NULL;

}

LookupRet findArray(char* a, int i) {
	int lower, upper;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	VariableList l = findVarList(a);
	if(l->type == EXPTYPE_ARRAY && l->pAttr != NULL) {
		lower = ((ArrayDef)(l->pAttr))->subBound->LowerBound.i;
		upper = ((ArrayDef)(l->pAttr))->subBound->UpperBound.i;
		if(i>=lower && i<=upper) {
			ret.totalOff = l->memloc.offset+OFFSET_INC*(i-lower);
			ret.jumpLevel = currentNestLevel - l->nestLevel;
			ret.type = l->type;
		}
	}
	return ret;
}

LookupRet findRecord(char* rec, char* a) {
	VariableList l = findVarList(rec);
	TypeList plist;
	int size = 0;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	if(l->type == EXPTYPE_RECORD && l->pAttr != NULL) {
		if(((RecordDef)(l->pAttr))->type == UNDEFINED) {
			plist = ((RecordDef)(l->pAttr))->ptr.pAnony;
		} else {
			plist = ((RecordDef)(l->pAttr))->ptr.pDef;
		}
		while(plist != NULL && strcmp(plist->name, a)) {
			size += 1;
			plist = plist->next;
		}
		if(plist != NULL) {
			ret.totalOff = size*OFFSET_INC + l->memloc.offset;
			ret.jumpLevel = currentNestLevel - l->nestLevel;
			ret.type = plist->type;
		}
	}
	return ret;
}

void initScope()
{
	currentNestLevel = -1;
}

int enterNewScope(TreeNode* t) {
	currentNestLevel += 1;
	totalOffset[currentNestLevel] = buildSymtable(t);
	return 	totalOffset[currentNestLevel];
}

int leaveScope() {
	int tmp = currentNestLevel;
	int retValue = totalOffset[currentNestLevel];
	void* ptr1, *ptr2, *ptr3;
	currentNestLevel -= 1;

    std::map<std::string, VariableList>::iterator itor;
    for (itor = variableMap.begin(); itor != variableMap.end(); itor++) {
        VariableList vl = itor->second;
        while(vl != NULL && vl->nestLevel >= tmp) {
            ptr1 = (void*)vl;
            vl = vl->next;
            ptr2 = (void*)(((VariableList)ptr1)->lines);
            while((LineList)ptr2 != NULL) {
                ptr3 = (void*)(((LineList)ptr2)->next);
                free((LineList)ptr2);
                ptr2 = ptr3;
            }
            free((VariableList)ptr1);
        }
        variableMap[itor->first] = vl;
    }
	return retValue;
}

