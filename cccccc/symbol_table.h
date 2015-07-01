#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "util.h"
#include "analyze.h"

typedef struct LookupRetRec {
	int totalOff;
	int jumpLevel;
	ExpType type;
} LookupRet;

typedef struct MemLocRec {
	int baseLoc;
	int offset;
	ExpType type;
} MemLoc;

typedef struct LineListRec {
	int lineno;
	struct LineListRec* next;
}* LineList;

typedef struct AliaseListRec {
	char* aliase;
	struct AliaseListRec* next;
}* AliaseList;

typedef union {
	int i;
	char c;
	char* m;
} Bound;

typedef struct SubBoundDefRec {
	ExpType boundType;
	Bound LowerBound;
	Bound UpperBound;
}* SubBoundDef;

typedef struct ArrayDefRec {
	ExpType arrayType;
	SubBoundDef subBound;
}* ArrayDef;

typedef struct EnumDefRec {
	char* mark;
	struct EnumDefRec* next;
}* EnumDef;

typedef enum {ANONYMOUS, DEFINED} RecordType;

typedef struct RecordNodeRec {
	RecordType type;
	union {
		struct TypeListRec* pDef;
		struct TypeListRec* pAnony;
	} ptr;
	struct RecordDefRec* next;
}* RecordDef;

typedef struct TypeListRec {
	char* name;
	AliaseList aliaseSet;
	ExpType type;
	int nestLevel;
	int size;
	void* pAttr;
	struct TypeListRec* next;
}* TypeList;

typedef struct VariableListRec {
	char* name;
	ExpType type;
	int isConst;
	int nestLevel;
	void* pAttr;
	LineList lines;
	MemLoc memloc;
	struct VariableListRec* next;
}* VariableList;

typedef struct SimpleTypeListRec {
	char* name;
	ExpType type;
	int isVar;
	struct SimpleTypeListRec* next;
}* SimpleTypeList;

typedef struct FuncListRec {
	char* name;
	SimpleTypeList paraList;
	ExpType retType;
	int nestLevel;
	struct FuncListRec* next;
}* FuncList;

typedef struct ProcListRec {
	char* name;
	SimpleTypeList paraList;
	int nestLevel;
	struct ProcListRec* next;
}* ProcList;

void initScope();
int enterNewScope(TreeNode* t);
int leaveScope();
void printSymbolTable();
VariableList findVarList(char* name);
FuncList findFuncList(char* name);
ProcList findProcList(char* name);
TypeList findTypeList(char* name);
LookupRet findArray(char* a, int i);
LookupRet findRecord(char* rec, char* a);

SubBoundDef newSubBoundDef(ExpType type, void* upper, void* lower);
ArrayDef newArrayDef(ExpType arrayType, ExpType boundType, void* upper, void* lower);
EnumDef newEnumDef(char* mark);
EnumDef insertEnumDef(EnumDef enumList, char* mark);
TypeList newTypeDef(char* name, ExpType type, int nestLevel, void* pAttr, int size);
TypeList insertTypeDef(TypeList typeList, char* name, ExpType type, int nestLevel, void* pAttr, int size);
RecordDef newDefinedRecord(TypeList ptr);
RecordDef newAnonyRecord(TypeList typeList);
SimpleTypeList newSimpleTypeList(char* name, ExpType type, int isVar);
SimpleTypeList insertSimpleTypeList(SimpleTypeList simpleList, char* name, ExpType type, int isVar);

int procListInsert(TreeNode* procHead);
int funcListInsert(TreeNode* funcHead);
void typeListAliaseInsert(char* name, char* aliase);
void typeListInsert(char* name, ExpType type, int nestLevel, void* pAttr, int size);
void varListInsert(char* name, ExpType type, int isConst, int nestLevel, void* pAttr, int lineno, int baseLoc, int offset);

#endif
