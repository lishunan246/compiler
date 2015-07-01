#include "global.h"
#include "util.h"

void printToken(TokenType token, const char * tokenString){
    switch(token){
        case ENDFILE:
            printf("EOF\n");break;
        case ERROR:
            printf("ERROR:%s\n",tokenString);

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
            printf("reserved word: %s\n", tokenString);
            break;

        case TOKEN_TO:
            printf("to\n");break;
        case TOKEN_DOWNTO:
            printf("down to\n");break;
        case TOKEN_READ:
            printf("read\n");break;
        case TOKEN_WRITE:
            printf("write\n");break;
        case TOKEN_WRITELN:
            printf("writeln\n");break;


        case TOKEN_EQUAL:   printf("=\n");break;
        case TOKEN_UNEQUAL:   printf("<>\n");break;
        case TOKEN_GE:   printf(">=\n");break;
        case TOKEN_GT:   printf(">\n");break;
        case TOKEN_LE:   printf("<=\n");break;
        case TOKEN_LT:   printf("<\n");break;
        case TOKEN_PLUS:    printf("+\n");break;
        case TOKEN_MINUS:   printf("-\n");break;
        case TOKEN_MUL:     printf("*\n");break;
        case TOKEN_DIV:     printf("\\n");break;
        case TOKEN_OR:      printf("or\n");break;
        case TOKEN_AND:     printf("and\n");break;
        case TOKEN_MOD:     printf("mod\n");break;

        case TOKEN_LB:      printf("[\n");break;
        case TOKEN_RB:      printf("]\n");break;
        case TOKEN_SEMI:    printf(";\n");break;
        case TOKEN_DOT:     printf(".\n");break;
        case TOKEN_DOTDOT:  printf(".\n");break;
        case TOKEN_LP:      printf("(\n");break;
        case TOKEN_RP:      printf(")\n");break;
        case TOKEN_COMMA:   printf(",\n");break;
        case TOKEN_COLON:   printf(":\n");break;

        case TOKEN_INTEGER_TYPE:
        case TOKEN_BOOLEAN_TYPE:
        case TOKEN_CHAR_TYPE:
        case TOKEN_REAL_TYPE:
        case TOKEN_ARRAY:
            printf("TYPE, name=%s\n",tokenString);break;

        case TOKEN_TRUE:
        case TOKEN_FALSE:
            printf("BOOLEAN, val=%s\n",tokenString);break;

        case TOKEN_INT: printf("INT, val=%s\n",tokenString);break;
        case TOKEN_REAL: printf("REAL, val=%s\n",tokenString);break;
        case TOKEN_CHAR: printf("CHAR, val=%s\n",tokenString);break;
        case TOKEN_STRING: printf("STRING, val=%s\n",tokenString);break;

        case TOKEN_ID: printf("ID name=%s\n",tokenString);break;

        case TOKEN_ABS: printf("abs\n");break;
        case TOKEN_CHR: printf("chr\n");break;
        case TOKEN_ODD: printf("odd\n");break;
        case TOKEN_ORD: printf("ord\n");break;
        case TOKEN_PRED:printf("pred\n");break;
        case TOKEN_SQR: printf("sqr\n");break;
        case TOKEN_SQRT:printf("sqrt\n");break;
        case TOKEN_SUCC:printf("succ\n");break;

        default:
            printf("Unknown token:%s\n",tokenString);
    }
}

TreeNode * newDeclNode(DeclKind kind){
    TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t==NULL)
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf("Out of memory error at line %d\n",lineno);
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
      printf(" ");
}

void printTree(TreeNode * tree){
    int i;
    INDENT;
    while(tree!=NULL){
        printSpaces();
        switch(tree->nodekind){
            case(NODE_STATEMENT):
                switch(tree->kind.stmt){
                    case STMT_LABEL:    printf("Stmt labelno%d\n",tree->attr.val);break;
                    case STMT_ASSIGN:   printf("Stmt Assign\n");break;
                    case STMT_GOTO:     printf("goto %d\n",tree->attr.val);break;
                    case STMT_IF:       printf("if\n");break;
                    case STMT_REPEAT:   printf("repeat\n");break;
                    case STMT_WHILE:    printf("while\n");break;
                    case STMT_CASE:     printf("case\n");break;
                    case STMT_FOR:      printf("for direction:");printToken(tree->attr.op,"\0");break;
                    case STMT_PROC_SYS:  printf("system procedure:");printToken(tree->attr.op,"\0");break;
                    case STMT_PROC_ID:   printf("procedure:");break;
                    default: printf("Unknown Statement type\n");break;
                }
            break;

            case(NODE_EXPRESSION):
               switch(tree->kind.exp){
                    case EXP_OP:
                        printf("EXP op: "); printToken(tree->attr.op,"\0");break;
                    case EXP_CONST:
                        switch(tree->type){
                            case EXPTYPE_INT: printf("const int:%d\n",tree->attr.val); break;
                            case EXPTYPE_REAL: printf("const real:%lf\n",tree->attr.real_val); break;
                            case EXPTYPE_CHAR: printf("const char:%c\n",tree->attr.char_val); break;
                            case EXPTYPE_STRING: printf("const string:%s\n",tree->attr.string_val); break;
                        }
                        break;
                    case EXP_ID: printf("Exp ID: %s\n",tree->attr.name); break;
                    case EXP_CASE: printf("Exp case:");break;
                    case EXP_FUNC_ID: printf("Func:");break;
                    case EXP_FUNC_SYS: printf("Sys func:");printToken(tree->attr.op,"\0");break;
                    default: printf("Unknown Expression type\n");
                }
            break;

            case(NODE_DECLARE):
                switch(tree->kind.decl){
                    case DECL_ROUTINEHEAD: printf("Routine Head\n");break;
                    case DECL_PROCEDURE: printf("Declare Procedure\n");break;
                    case DECL_PROCEDUREHEAD: printf("Procedure Head %s\n",tree->attr.name);break;
                    case DECL_CONST: printf("Const Declare:\n");break;
                    case DECL_TYPE: printf("Type Declare:\n");break;
                    case DECL_VAR: printf("Var Declare:\n");break;
                    case DECL_FUNCTION: printf("Declare Function \n");break;
                    case DECL_FUNCTIONHEAD:printf("Function Head:%s\n",tree->attr.name);break;
                    case DECL_VAR_PARA:printf("var parameter:\n");break;
                    case DECL_VAL_PARA:printf("val parameters:\n");break;
                }
            break;

            case(NODE_TYPE):
                switch(tree->kind.type){
                    case TYPE_SIMPLE_SYS:
                        switch(tree->type){
                            case EXPTYPE_INT:printf("type integer\n");break;
                            case EXPTYPE_REAL:printf("type real\n");break;
                            case EXPTYPE_CHAR:printf("type char\n");break;
                            case EXPTYPE_BOOL:printf("type boolean\n");break;
                        }
                    break;
                    case TYPE_SIMPLE_ID: printf("type id\n"); break;
                    case TYPE_SIMPLE_ENUM: printf("type enum\n"); break;
                    case TYPE_SIMPLE_LIMIT: printf("type limit\n"); break;
                    case TYPE_ARRAY: printf("type array\n");break;
                    case TYPE_RECORD: printf("type record\n");break;
                    default: printf("Unknown type\n");break;
                }
            break;

            default: printf("Unknown node kind\n"); break;
        }

        for(i=0;i<MAXCHILDREN;i++)
          printTree(tree->child[i]);
        tree=tree->sibling;
    }
    UNINDENT;
}

















