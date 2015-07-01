#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "analyze.h"

#include <iostream>
#include <string>
#include <map>

#define ERROR_RETURN 0xffff

/*define size of the hash table*/
#define SIZE 211

int currentNestLevel = 0;

/*the hash function*/
static int hash (char* key) {
	int temp = 0;
	int i = 0;
	while(key[i] != '\0') {
		temp = ((temp << 4) + key[i]) % SIZE;
		++i;
	}

	return temp;
}

/*===============定义符号表，分为变量、类型、函数、过程四个子表================*/



/*the hash table of variables*/
static VariableList variableHashTable[SIZE];

static std::map<std::string,VariableList> variableMap;

// symbol map of type define
static std::map<std::string, TypeList> typeMap;

// symbol maps of func and proc
static std::map<std::string, FuncList> funcMap;
static std::map<std::string, ProcList> procMap;

/*record the total offset of each scope*/
static int totalOffset[50];



/*=========================定义对符号表的插入操作=================================*/

/*build a p sub-bound type definition*/
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

/*build a p array definition*/
ArrayDef newArrayDef(ExpType arrayType, ExpType boundType, void* lower, void* upper) {
	ArrayDef p = (ArrayDef) malloc(sizeof(struct ArrayDefRec));
	p->arrayType = arrayType;
	p->subBound = newSubBoundDef(boundType, lower, upper);

	return p;
}

/*build a p enum definition*/
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

/*build a p type list node*/
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

/*build a p record definition*/
RecordDef newDefinedRecord(TypeList ptr) {
	RecordDef p = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	p->type = DEFINED;
	p->ptr.pDef = ptr;
	p->next = NULL;

	return p;
}

RecordDef newAnonyRecord(TypeList typeList) {
	RecordDef p = (RecordDef) malloc(sizeof(struct RecordNodeRec));
	p->type = ANONYMOUS;
	p->ptr.pAnony = typeList;
	p->next = NULL;

	return p;
}

/*build a simple type list*/
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

/*insert line numbers and memory location into the process hash table*/
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

/*insert line numbers and memory location into the function hash table*/
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
			//若传递参数为实参
			paraList = newSimpleTypeList(funcHead->child[0]->child[0]->attr.name, funcHead->child[0]->child[1]->type, true);
		} else {
			//若传递参数为形参
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

	//符号表插入返回值,与函数同名
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


/*insert line numbers and memory location into the type hash table*/
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

/*insert line numbers and memory location into the variable hash table*/
void varListInsert(char* name, ExpType type, int isConst, int nestLevel,
                   void* pAttr, int lineno, int baseLoc, int offset) {
	int h = hash(name);
	VariableList l = variableHashTable[h];
	VariableList tmp = l;
	while((tmp != NULL) && (strcmp(name, tmp->name)))
			tmp = tmp->next;
	if(tmp == NULL || (strcmp(name, tmp->name)==0 && nestLevel>tmp->nestLevel)) { /*process with same nestlevel not yet in the table, insert to the list head*/
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
		tmp->next = (l == NULL)? NULL:l;
		variableHashTable[h] = tmp;
	} else { /*find the exact variable*/
		LineList t = tmp->lines;
		while(t->next != NULL)
			t = t->next;
		t->next = (LineList) malloc(sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
	}
}

/*=======================定义对符号表的查找操作=================================*/

/*varListLookup returns the VariableList or null if not found*/
VariableList varListLookup(char* name) {
	int h = hash(name);
	VariableList l = variableHashTable[h];
	while((l != NULL) && (strcmp(name, l->name)))
		l = l->next;
	if(l == NULL)
		return NULL;
	else {
		l->memloc.baseLoc = currentNestLevel - l->nestLevel;
		return l;
	}
}

/*funcListLookup returns the FuncList of that name or null if not found*/
FuncList funcListLookup(char* name) {
    if (funcMap.count(std::string(name)) > 0) {
        return funcMap[std::string(name)];
    }
    return NULL;
}

/*procListLookup returns the ProcList of that name or null if not found*/
ProcList procListLookup(char* name) {
    if (procMap.count(std::string(name)) > 0) {
        return procMap[std::string(name)];
    }
    return NULL;
}

/*typeListLookup returns the TypeList of that name or null if not found*/
TypeList typeListLookup(char* name) {
    if (typeMap.count(std::string(name)) > 0) {
        return typeMap[std::string(name)];
    }
    return NULL;

}

/*array Lookup*/
LookupRet arrayLookup(char* a, int i) {
	int lower, upper, size;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	VariableList l = varListLookup(a);
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

/*recordLookup*/
LookupRet recordLookup(char* rec, char* a) {
	VariableList l = varListLookup(rec);
	TypeList plist;
	int size = 0;
	LookupRet ret;
	ret.totalOff = ERROR_RETURN;
	ret.jumpLevel = ERROR_RETURN;
	ret.type = EXPTYPE_VOID;
	if(l->type == EXPTYPE_RECORD && l->pAttr != NULL) {
		if(((RecordDef)(l->pAttr))->type == ANONYMOUS) {
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


/*===================定义进出函数或过程时对符号表的更新==========================*/

/*initialize*/
void initScope() {
	currentNestLevel = -1;
	int i;
	for(i=0; i<SIZE; i++) {
		variableHashTable[i] = NULL;
	}
}

/*enter p function or process scope*/
int enterNewScope(TreeNode* t) {
	currentNestLevel += 1;
	totalOffset[currentNestLevel] = buildSymtab(t);
	return 	totalOffset[currentNestLevel];
}

/*quit function or process scope*/
int leaveScope() {
	int tmp = currentNestLevel;
	int retValue = totalOffset[currentNestLevel];
	void* ptr1, *ptr2, *ptr3;
	currentNestLevel -= 1;
	int i;
	for(i=0; i<SIZE; i++) {
		VariableList vl = variableHashTable[i];

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
		variableHashTable[i] = vl;
	}
	return retValue;
}


/*=======================定义对符号表的打印操作=================================*/

/*print symbol table*/
void printSymTab(FILE* listing) {
	int i;
	fprintf(listing, "Variable Name		NestLevel 	Location 	Line Number\n");
	fprintf(listing, "------------- 	---------	-------- 	-----------\n");
	for(i=0; i<SIZE; i++) {
		if(variableHashTable[i] != NULL) {
			VariableList l = variableHashTable[i];
			while(l != NULL) {
				LineList t = l->lines;
				fprintf(listing, "%-14s ", l->name);
				fprintf(listing, "%-8d", l->nestLevel);
				fprintf(listing, "%-8d ", l->memloc.offset);
				while(t != NULL) {
					fprintf(listing, "%4d ", t->lineno);
					t = t->next;
				}
				fprintf(listing, "\n");
				l = l->next;
			}
		}
	}

	fprintf(listing, "Function Name		NestLevel 	Return Type 	Parameter\n");
	fprintf(listing, "------------- 	---------	-------- 	-----------\n");
    
    std::map<std::string, FuncList>::iterator itor;
    for (itor = funcMap.begin(); itor != funcMap.end(); itor++) {
        FuncList l = itor->second;
        SimpleTypeList t = l->paraList;
        fprintf(listing, "%-14s ", l->name);
        fprintf(listing, "%-8d", l->nestLevel);
        fprintf(listing, "%-8d ", l->retType);
        while(t != NULL) {
            fprintf(listing, "%-14s ", t->name);
            t = t->next;
        }
        fprintf(listing, "\n");
    }
}
