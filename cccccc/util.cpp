#include <iostream>
#include "global.h"
#include "util.h"

void printToken(TokenType token, const char * tokenString){
    switch(token){
        case ENDFILE:
            std::cout<<"EOF"<<std::endl;break;
        case ERROR:
            std::cout<<"ERROR:"<<tokenString<<std::endl;

        case TOKEN_PROGRAM:
        case TOKEN_CONST:
        case TOKEN_TYPE:
        case TOKEN_VAR:
        case TOKEN_PROCEDURE:
        case TOKEN_FUNCTION:
        case TOKEN_OF:
        case TOKEN_BEGIN:
        case TOKEN_END:
        case TOKEN_IF:
        case TOKEN_THEN:
        case TOKEN_ELSE:
            std::cout<<"reserved word: "<<tokenString<<std::endl;
            break;

        case TOKEN_TO:
            std::cout<<"to"<<std::endl;break;
        case TOKEN_DOWNTO:
            std::cout<<"down to"<<std::endl;break;
        case TOKEN_READ:
            std::cout<<"read"<<std::endl;break;
        case TOKEN_WRITE:
            std::cout<<"write"<<std::endl;break;
        case TOKEN_WRITELN:
            std::cout<<"writeln"<<std::endl;break;


        case TOKEN_EQUAL:   std::cout<<"="<<std::endl;break;
        case TOKEN_UNEQUAL:   std::cout<<"<>"<<std::endl;break;
        case TOKEN_GE:   std::cout<<">="<<std::endl;break;
        case TOKEN_GT:   std::cout<<">"<<std::endl;break;
        case TOKEN_LE:   std::cout<<"<="<<std::endl;break;
        case TOKEN_LT:   std::cout<<"<"<<std::endl;break;
        case TOKEN_PLUS:    std::cout<<"+"<<std::endl;break;
        case TOKEN_MINUS:   std::cout<<"-"<<std::endl;break;
        case TOKEN_MUL:     std::cout<<"*"<<std::endl;break;
        case TOKEN_DIV:     std::cout<<"\\"<<std::endl;break;
        case TOKEN_OR:      std::cout<<"or"<<std::endl;break;
        case TOKEN_AND:     std::cout<<"and"<<std::endl;break;
        case TOKEN_MOD:     std::cout<<"mod"<<std::endl;break;

        case TOKEN_LB:      std::cout<<"["<<std::endl;break;
        case TOKEN_RB:      std::cout<<"]"<<std::endl;break;
        case TOKEN_SEMI:    std::cout<<";"<<std::endl;break;
        case TOKEN_DOT:     std::cout<<"."<<std::endl;break;
        case TOKEN_DOTDOT:  std::cout<<"."<<std::endl;break;
        case TOKEN_LP:      std::cout<<"("<<std::endl;break;
        case TOKEN_RP:      std::cout<<")"<<std::endl;break;
        case TOKEN_COMMA:   std::cout<<","<<std::endl;break;
        case TOKEN_COLON:   std::cout<<":"<<std::endl;break;

        case TOKEN_INTEGER_TYPE:
        case TOKEN_BOOLEAN_TYPE:
        case TOKEN_CHAR_TYPE:
        case TOKEN_REAL_TYPE:
        case TOKEN_ARRAY:
            std::cout<<"TYPE, name="<<tokenString<<std::endl;break;

        case TOKEN_TRUE:
        case TOKEN_FALSE:
            std::cout<<"BOOLEAN, val="<<tokenString<<std::endl;break;

        case TOKEN_INT: std::cout<<"INT, val="<<tokenString<<std::endl;break;
        case TOKEN_REAL: std::cout<<"REAL, val="<<tokenString<<std::endl;break;
        case TOKEN_CHAR: std::cout<<"CHAR, val="<<tokenString<<std::endl;break;
        case TOKEN_STRING: std::cout<<"STRING, val="<<tokenString<<std::endl;break;

        case TOKEN_ID: std::cout<<"ID name="<<tokenString<<std::endl;break;

        case TOKEN_ABS: std::cout<<"abs"<<std::endl;break;
        case TOKEN_CHR: std::cout<<"chr"<<std::endl;break;
        case TOKEN_ODD: std::cout<<"odd"<<std::endl;break;
        case TOKEN_ORD: std::cout<<"ord"<<std::endl;break;
        case TOKEN_PRED:std::cout<<"pred"<<std::endl;break;
        case TOKEN_SQR: std::cout<<"sqr"<<std::endl;break;
        case TOKEN_SQRT:std::cout<<"sqrt"<<std::endl;break;
        case TOKEN_SUCC:std::cout<<"succ"<<std::endl;break;

        default:
            std::cout<<"Unknown token:"<<tokenString<<std::endl;
    }
}

TreeNode * newDeclNode(DeclKind kind){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_DECLARE;
        t->kind.decl = kind;
        t->lineno=lineno;
    }
    return t;
}


TreeNode * newStmtNode(StmtKind kind){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_STATEMENT;
        t->kind.stmt=kind;
        t->lineno=lineno;
    }
    return t;
}


TreeNode * newExpNode(ExpKind kind){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_EXPRESSION;
        t->kind.exp=kind;
        t->lineno=lineno;
        t->type = EXPTYPE_VOID;
    }
    return t;
}

TreeNode * newOpExpNode(TreeNode * first, TreeNode * second, TokenType op){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_EXPRESSION;
        t->kind.exp=EXP_OP;
        t->attr.op=op;
        t->lineno=lineno;
        t->child[0]=first;
        t->child[1]=second;
    }
    return t;

}

TreeNode * newTypeNode(TypeKind type){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_TYPE;
        t->kind.type=type;
        t->lineno=lineno;
    }
    return t;
}

TreeNode * newFuncSysExpNode(TokenType op, TreeNode* args){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else{
        for(i=0;i<MAXCHILDREN;i++)
          t->child[i]=NULL;
        t->sibling=NULL;
        t->nodekind=NODE_EXPRESSION;
        t->kind.exp=EXP_FUNC_SYS;
        t->child[0]=args;
        t->attr.op=op;
        t->lineno=lineno;
    }
    return t;

}

void freeNode(TreeNode *node){
    int i;
    for(i=0;i<MAXCHILDREN;i++)
      free(node->child[i]);
    free(node->sibling);
    free(node);
}


char* copyString(char *s){
    int n;
    char *t;
    if(s==NULL)
      return NULL;
    n=strlen(s)+1;
    t=(char*)malloc(n);
    if(t==NULL)
      std::cout<<"Out of memory error at line "<<lineno<<std::endl;
    else
      strcpy(t,s);
    return t;
}

//used for printTree
static int indentno=0;
#define INDENT indentno+=2
#define UNINDENT indentno-=2

static void printSpaces(void){
    int i;
    for(i=0;i<indentno;i++)
      std::cout<<" ";
}

void printTree(TreeNode * tree){
    int i;
    INDENT;
    while(tree!=NULL){
        printSpaces();
        switch(tree->nodekind){
            case(NODE_STATEMENT):
                switch(tree->kind.stmt){
                    case STMT_LABEL:    std::cout<<"Stmt labelno"<<tree->attr.val<<std::endl;break;
                    case STMT_ASSIGN:   std::cout<<"Stmt Assign"<<std::endl;break;
                    case STMT_GOTO:     std::cout<<"goto "<<tree->attr.val<<std::endl;break;
                    case STMT_IF:       std::cout<<"if"<<std::endl;break;
                    case STMT_REPEAT:   std::cout<<"repeat"<<std::endl;break;
                    case STMT_WHILE:    std::cout<<"while"<<std::endl;break;
                    case STMT_CASE:     std::cout<<"case"<<std::endl;break;
                    case STMT_FOR:      std::cout<<"for direction:"<<std::endl;printToken(tree->attr.op,"\0");break;
                    case STMT_PROC_SYS:  std::cout<<"system procedure:"<<std::endl;printToken(tree->attr.op,"\0");break;
                    case STMT_PROC_ID:   std::cout<<"procedure:";break;
                    default: std::cout<<"Unknown Statement type"<<std::endl;break;
                }
            break;

            case(NODE_EXPRESSION):
               switch(tree->kind.exp){
                    case EXP_OP:
                        std::cout<<"EXP op: "; printToken(tree->attr.op,"\0");break;
                    case EXP_CONST:
                        switch(tree->type){
                            case EXPTYPE_INT: std::cout<<"const int:"<<tree->attr.val<<std::endl; break;
                            case EXPTYPE_REAL: std::cout<<"const real:"<<tree->attr.real_val<<std::endl; break;
                            case EXPTYPE_CHAR: std::cout<<"const char:"<<tree->attr.char_val<<std::endl; break;
                            case EXPTYPE_STRING: std::cout<<"const string:"<<tree->attr.string_val<<std::endl; break;
                        }
                        break;
                    case EXP_ID: std::cout<<"Exp ID: "<<tree->attr.name<<std::endl;break;
                    case EXP_CASE: std::cout<<"Exp case:";break;
                    case EXP_FUNC_ID: std::cout<<"Func:";break;
                    case EXP_FUNC_SYS: std::cout<<"Sys func:";printToken(tree->attr.op,"\0");break;
                    default: std::cout<<"Unknown Expression type"<<std::endl;
                }
            break;

            case(NODE_DECLARE):
                switch(tree->kind.decl){
                    case DECL_ROUTINEHEAD: std::cout<<"Routine Head"<<std::endl;break;
                    case DECL_PROCEDURE: std::cout<<"Declare Procedure"<<std::endl;break;
                    case DECL_PROCEDUREHEAD: std::cout<<"Procedure Head "<<tree->attr.name<<std::endl;break;
                    case DECL_CONST: std::cout<<"Const Declare:"<<std::endl;break;
                    case DECL_TYPE: std::cout<<"Type Declare:"<<std::endl;break;
                    case DECL_VAR: std::cout<<"Var Declare:"<<std::endl;break;
                    case DECL_FUNCTION: std::cout<<"Declare Function "<<std::endl;break;
                    case DECL_FUNCTIONHEAD:std::cout<<"Function Head:"<<tree->attr.name<<std::endl;break;
                    case DECL_VAR_PARA:std::cout<<"var parameter:"<<std::endl;break;
                    case DECL_VAL_PARA:std::cout<<"val parameters:"<<std::endl;break;
                }
            break;

            case(NODE_TYPE):
                switch(tree->kind.type){
                    case TYPE_SIMPLE_SYS:
                        switch(tree->type){
                            case EXPTYPE_INT:std::cout<<"type integer"<<std::endl;break;
                            case EXPTYPE_REAL:std::cout<<"type real"<<std::endl;break;
                            case EXPTYPE_CHAR:std::cout<<"type char"<<std::endl;break;
                            case EXPTYPE_BOOL:std::cout<<"type boolean"<<std::endl;break;
                        }
                    break;
                    case TYPE_SIMPLE_ID: std::cout<<"type id"<<std::endl; break;
                    case TYPE_SIMPLE_ENUM: std::cout<<"type enum"<<std::endl; break;
                    case TYPE_SIMPLE_LIMIT: std::cout<<"type limit"<<std::endl; break;
                    case TYPE_ARRAY: std::cout<<"type array"<<std::endl;break;
                    case TYPE_RECORD: std::cout<<"type record"<<std::endl;break;
                    default: std::cout<<"Unknown type"<<std::endl;break;
                }
            break;

            default: std::cout<<"Unknown node kind"<<std::endl; break;
        }

        for(i=0;i<MAXCHILDREN;i++)
          printTree(tree->child[i]);
        tree=tree->sibling;
    }
    UNINDENT;
}

















