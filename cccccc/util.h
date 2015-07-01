#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>


#ifndef YYPARSER
#include "y.tab.h"
#endif

#define MAXCHILDREN 4
#define MAXRESERVED 8
#define MAXTOKENLEN 40
typedef int TokenType;
extern FILE* source;

extern int lineno;
extern bool TraceScan;
extern char tokenString[MAXTOKENLEN+1];
extern char previoustokenString[MAXTOKENLEN+1];


typedef enum{
    NODE_STATEMENT, NODE_EXPRESSION, NODE_DECLARE, NODE_TYPE
}NodeKind;

typedef enum{
    STMT_LABEL,
    STMT_ASSIGN,STMT_GOTO,STMT_IF,STMT_REPEAT,STMT_WHILE,STMT_FOR,STMT_CASE,
    STMT_PROC_ID,STMT_PROC_SYS
}StmtKind;

typedef enum{
    EXP_ID,
    EXP_CONST,
    EXP_OP,EXP_CASE,EXP_FUNC_ID,EXP_FUNC_SYS
}ExpKind;

typedef enum{
    DECL_ROUTINEHEAD,
    DECL_FUNCTION,DECL_FUNCTIONHEAD,
    DECL_PROCEDURE,DECL_PROCEDUREHEAD,
    DECL_CONST,DECL_VAR,DECL_TYPE,
    DECL_VAR_PARA,DECL_VAL_PARA
}DeclKind;

typedef enum{
    TYPE_SIMPLE_SYS,TYPE_SIMPLE_ID, TYPE_SIMPLE_ENUM, TYPE_SIMPLE_LIMIT,
    TYPE_ARRAY, TYPE_RECORD
}TypeKind;

typedef enum{
    EXPTYPE_VOID,EXPTYPE_INT,EXPTYPE_REAL,
    EXPTYPE_CHAR,EXPTYPE_STRING,EXPTYPE_BOOL,
    EXPTYPE_ARRAY,EXPTYPE_RECORD,
    EXPTYPE_SIMPLE_ID,EXPTYPE_SIMPLE_ENUM,EXPTYPE_SIMPLE_LIMIT
}ExpType;



typedef struct treeNode{
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    NodeKind nodekind;
    int lineno;
    union{ 
        StmtKind stmt;
        ExpKind exp;
        DeclKind decl;
        TypeKind type;
    }kind;
    union{
        TokenType op;
        char * name;
        int val;
        char char_val;
        char * string_val;
        double real_val;
    }attr;
    ExpType type;
    ExpType RuningType;
}TreeNode;

void printToken(TokenType, const char *);

TreeNode * newStmtNode(StmtKind s);

TreeNode * newExpNode(ExpKind e);
TreeNode * newOpExpNode(TreeNode*, TreeNode*,TokenType);
TreeNode * newFuncSysExpNode(TokenType op, TreeNode* args);

TreeNode * newDeclarationNode(DeclKind d);

TreeNode * newTypeNode(TypeKind type);


void freeNode(TreeNode*);

char * copyString(char*);

void printTree(TreeNode *);

#endif
