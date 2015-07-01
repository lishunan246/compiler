%{
#define YYPARSER
#include "util.h"
#define YYSTYPE TreeNode *
static char * myName;
static TreeNode* myTree;
static int myNum;
static int level=0;
TokenType getToken();

int yyparse();
static int yylex(){
    return getToken();
}

int yyerror(char* message) {
    printf( "Syntax error at line %d: %s\n",lineno,message);
    return 0;
}

%}
%token TOKEN_PROGRAM TOKEN_FUNCTION TOKEN_PROCEDURE TOKEN_CONST TOKEN_TYPE TOKEN_VAR TOKEN_IF TOKEN_THEN TOKEN_ELSE TOKEN_REPEAT TOKEN_UNTIL TOKEN_WHILE TOKEN_DO TOKEN_CASE TOKEN_TO TOKEN_DOWNTO TOKEN_FOR TOKEN_EQUAL TOKEN_UNEQUAL TOKEN_GE TOKEN_GT TOKEN_LE TOKEN_LT TOKEN_ASSIGN TOKEN_PLUS TOKEN_MINUS TOKEN_MUL TOKEN_DIV TOKEN_OR TOKEN_AND TOKEN_NOT TOKEN_MOD TOKEN_READ TOKEN_WRITE TOKEN_WRITELN TOKEN_LB TOKEN_RB TOKEN_SEMI TOKEN_DOT TOKEN_DOTDOT TOKEN_LP TOKEN_RP TOKEN_COMMA TOKEN_COLON TOKEN_INTEGER_TYPE TOKEN_BOOLEAN_TYPE TOKEN_CHAR_TYPE TOKEN_REAL_TYPE TOKEN_TRUE TOKEN_FALSE TOKEN_MAXINT TOKEN_ARRAY TOKEN_OF TOKEN_RECORD TOKEN_BEGIN TOKEN_END TOKEN_GOTO TOKEN_ID TOKEN_INT TOKEN_REAL TOKEN_CHAR TOKEN_STRING ERROR TOKEN_ABS TOKEN_CHR TOKEN_ODD TOKEN_ORD TOKEN_PRED TOKEN_SQR TOKEN_SQRT TOKEN_SUCC TOKEN_READLN
%%

program             :   TOKEN_PROGRAM TOKEN_ID
                        {   
                            myName = copyString(tokenString);
                        }
                        TOKEN_SEMI routine TOKEN_DOT
                        {   $$ = $5;
                            $$->attr.name=myName;
                            myTree = $$;
                        };
/*
program_head        :   TOKEN_PROGRAM TOKEN_ID
                        {   
                            myName = copyString(tokenString);
                        }
                        TOKEN_SEMI 
*/ 
routine             :   routine_head routine_body
                        {
                            $$ = $1;
                            $$->sibling=$2;
                        };
routine_head        :   const_part type_part var_part routine_part
                        {
                            $$ = newDeclarationNode(DECL_ROUTINEHEAD);
                            $$ ->child[0]=$1;
                            $$ ->child[1]=$2;
                            $$ ->child[2]=$3;
                            $$ ->child[3]=$4;
                        };
const_part          :   TOKEN_CONST const_expr_list
                        {   
                            $$=$2; 
                        }
                    |   {   
                            $$ = NULL; 
                        }  
                    ;
const_expr_list     :   const_expr_list const_expr
                        {
                            YYSTYPE t = $1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling = $2;
                                $$=$2;
                            }
                            else
                                $$=$1;
                        }

                    |   const_expr
                        {   
                            $$=$1; 
                        }
                    ;
const_expr          :    ID TOKEN_EQUAL const_value TOKEN_SEMI
                        {
                            $$ = newDeclarationNode(DECL_CONST);
                            $$->attr.name = copyString($1->attr.name);
                            $$->child[0]=$3;
                            $$->type=$3->type;
                            freeNode($1);
                            
                        }
                    ;
const_value         :   TOKEN_INT
                        {
                            $$ = newExpNode(EXP_CONST);
                            $$->type = EXPTYPE_INT;
                            $$->attr.val = atoi(tokenString);
                        }
                    |   TOKEN_REAL
                        {
                            $$ = newExpNode(EXP_CONST);
                            $$->type = EXPTYPE_REAL;
                            $$->attr.real_val = atof(tokenString);
                        }
                    |   TOKEN_CHAR
                        {
                            $$ = newExpNode(EXP_CONST);
                            $$->type = EXPTYPE_CHAR;
                            $$->attr.char_val = tokenString[1];
                        }
                    |   TOKEN_STRING
                        {
                            $$ = newExpNode(EXP_CONST);
                            $$->type=EXPTYPE_STRING;
                            $$->attr.string_val = (char*)malloc(strlen(tokenString)-1);
                            memmove($$->attr.string_val,tokenString+1,strlen(tokenString)-2);
                            $$->attr.string_val[strlen(tokenString)-2]='\0';
                        }
                    |   TOKEN_TRUE
                        {
                            $$=newExpNode(EXP_CONST);
                            $$->type=EXPTYPE_BOOL;
                            $$->attr.val=1;
                        }
                    |   TOKEN_FALSE
                        {
                            $$=newExpNode(EXP_CONST);
                            $$->type=EXPTYPE_BOOL;
                            $$->attr.val=0;
                        }
                    |   TOKEN_MAXINT
                        {
                            $$=newExpNode(EXP_CONST);
                            $$->type=EXPTYPE_INT;
                            $$->attr.val=2147483647;
                        }
                    ;
type_part           :
                        TOKEN_TYPE type_decl_list
                        {   
                            $$=$2;
                        }
                    |   {   
                            $$=NULL;
                        }
                    ;
type_decl_list      :   type_decl_list  type_definition
                        {
                            YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                              $$=$2;
                        }
                    |   type_definition
                        {   
                            $$=$1;
                        }
                    ;
type_definition     :   ID TOKEN_EQUAL type_decl TOKEN_SEMI
                        {   $$=newDeclarationNode(DECL_TYPE);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
type_decl           :   simple_type_decl    {
                            $$=$1;
                        }
                    |   array_type_decl     {
                            $$=$1;
                        }
                    |   record_type_decl    {
                            $$=$1;
                        }
                    ;
array_type_decl     :   TOKEN_ARRAY TOKEN_LB simple_type_decl TOKEN_RB TOKEN_OF 
                        type_decl
                        {
                            $$=newTypeNode(TYPE_ARRAY);
                            $$->type=EXPTYPE_ARRAY;
                            $$->child[0]=$3;
                            $$->child[1]=$6;
                            
                        }
                    ;
record_type_decl    :   TOKEN_RECORD field_decl_list TOKEN_END
                        {   
                            $$=$2; 
                        }
                    ;
field_decl_list     :   field_decl_list field_decl
                        {
                            YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                              $$=$2;
                        }
                    |   field_decl {$$=$1;}
                    ;
field_decl          :   name_list TOKEN_COLON type_decl TOKEN_SEMI
                        {
                            $$=newTypeNode(TYPE_RECORD);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
name_list           :   name_list TOKEN_COMMA ID
                        {
                            YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$3;
                                $$=$1;
                            }
                            else
                                $$=$1;
                        }
                    |   ID {   $$=$1; }
                    ;
simple_type_decl    :   ID
                        {
                            $$=newTypeNode(TYPE_SIMPLE_ID);
                            $$->attr.name = copyString($1->attr.name);
                            free($1);
                        }
                    |   TOKEN_LP name_list TOKEN_RP
                        {   $$=newTypeNode(TYPE_SIMPLE_ENUM);
                            $$->type=EXPTYPE_SIMPLE_ENUM;
                            $$->child[0]=$2;
                        }
                    |   const_value TOKEN_DOTDOT const_value
                        {   $$=newTypeNode(TYPE_SIMPLE_LIMIT);
                            $$->type=EXPTYPE_SIMPLE_LIMIT;
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    |   TOKEN_MINUS const_value TOKEN_DOTDOT const_value
                        {
                            $$=newTypeNode(TYPE_SIMPLE_LIMIT);
                            $$->type=EXPTYPE_SIMPLE_LIMIT;
                            $$->child[0]=$2;
                            $$->child[0]->attr.val *= -1;
                            $$->child[1]=$4;
                        }
                    |   TOKEN_MINUS const_value TOKEN_DOTDOT TOKEN_MINUS const_value
                        {   $$=newTypeNode(TYPE_SIMPLE_LIMIT);
                            $$->type=EXPTYPE_SIMPLE_LIMIT;
                            $$->child[0]=$2;
                            $$->child[0]->attr.val *=-1;
                            $$->child[1]=$5;
                            $$->child[1]->attr.val *=-1;
                        }
                    |   ID TOKEN_DOTDOT ID
                        {
                            $$=newTypeNode(TYPE_SIMPLE_LIMIT);
                            $$->type=EXPTYPE_SIMPLE_LIMIT;
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    |   TOKEN_INTEGER_TYPE
                        {   $$=newTypeNode(TYPE_SIMPLE_SYS);
                            $$->type=EXPTYPE_INT;
                        }
                    |   TOKEN_BOOLEAN_TYPE
                        {   $$=newTypeNode(TYPE_SIMPLE_SYS);
                            $$->type=EXPTYPE_BOOL;
                        }
                    |   TOKEN_REAL_TYPE
                        {   $$=newTypeNode(TYPE_SIMPLE_SYS);
                            $$->type=EXPTYPE_REAL;
                        }
                    |   TOKEN_CHAR_TYPE
                        {   $$=newTypeNode(TYPE_SIMPLE_SYS);
                            $$->type=EXPTYPE_CHAR;
                        }
                    ;
var_part            :
                        {   
                            $$ = NULL;
                        }
                    |   TOKEN_VAR var_decl_list
                        {   
                            $$=$2;
                        }
                    ;
var_decl_list       :   var_decl_list var_decl
                        {   YYSTYPE t = $1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   var_decl    {
                            $$=$1;
                        }
                    ;
var_decl            :   name_list TOKEN_COLON type_decl TOKEN_SEMI
                        {   $$=newDeclarationNode(DECL_VAR);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
routine_part        :
                        {   
                            $$= NULL;
                        }
                    |   routine_part function_decl
                        {   YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   routine_part procedure_decl
                        {   YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   function_decl   {$$=$1;}
                    |   procedure_decl  {$$=$1;}
                    ;
function_decl       :   function_head TOKEN_SEMI routine TOKEN_SEMI
                        {
                            $$=newDeclarationNode(DECL_FUNCTION);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
function_head       :   TOKEN_FUNCTION TOKEN_ID
                        {   myName=copyString(tokenString);}
                        parameters  TOKEN_COLON simple_type_decl
                        {
                            $$=newDeclarationNode(DECL_FUNCTIONHEAD);
                            $$->attr.name=myName;
                            $$->child[0]=$4;
                            $$->child[1]=$6;
                        }
                    ;
procedure_decl      :   procedure_head TOKEN_SEMI routine TOKEN_SEMI
                        {
                            $$=newDeclarationNode(DECL_PROCEDURE);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
procedure_head      :   TOKEN_PROCEDURE TOKEN_ID
                        {   myName=copyString(tokenString);}
                        parameters
                        {   $$=newDeclarationNode(DECL_PROCEDUREHEAD);
                            $$->attr.name=myName;
                            $$->child[0]=$4;
                        }
                    ;
parameters          :
                        {
                            $$=NULL;
                        }
                    |   TOKEN_LP para_decl_list TOKEN_RP
                        {
                            $$=$2;
                        }
                    ;
para_decl_list      :   para_decl_list  TOKEN_SEMI  para_type_list
                        {   YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$3;
                                $$=$1;
                            }
                            else
                                $$=$3;
                        }
                    |   para_type_list
                        {   
                            $$=$1; 
                        }
                    ;
para_type_list      :   TOKEN_VAR name_list TOKEN_COLON simple_type_decl
                        {
                            $$=newDeclarationNode(DECL_VAR_PARA);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                        }
                    |   name_list TOKEN_COLON simple_type_decl
                        {
                            $$=newDeclarationNode(DECL_VAL_PARA);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    ;
ID                  :   TOKEN_ID
                        {   $$=newExpNode(EXP_ID);
                            $$->attr.name=copyString(tokenString);
                        } ;
routine_body        :   compound_stmt   {
                            $$=$1;
                        } 
                    ;
compound_stmt       :   TOKEN_BEGIN stmt_list TOKEN_END {
                            $$=$2;
                        }
                    ;
stmt_list           :
                        {
                            $$=NULL;
                        }
                    |   stmt_list stmt TOKEN_SEMI
                        {
                            YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    ;
stmt                :   TOKEN_INT
                        {   
                            myNum= atoi(tokenString);
                        }
                        TOKEN_COLON no_label_stmt
                        {
                            $$=newStatementNode(STMT_LABEL);
                            $$->attr.val=myNum;
                            $$->child[0]=$4;
                        }
                    |   no_label_stmt
                        {   
                            $$=$1;
                        }
                    ;
no_label_stmt       :   assign_stmt {
                            $$=$1;
                        }
                    |   compound_stmt   {
                            $$=$1;
                        }
                    |   goto_stmt   {
                            $$=$1;
                        }
                    |   if_stmt     {
                            $$=$1;
                        }
                    |   repeat_stmt {
                            $$=$1;
                        }
                    |   while_stmt  {
                            $$=$1;
                        }
                    |   case_stmt   {
                            $$=$1;
                        }
                    |   for_stmt    {
                            $$=$1;
                        }
                    |   proc_stmt   {
                            $$=$1;
                        }
                    ;
assign_stmt         :   ID TOKEN_ASSIGN expression
                        {   $$=newStatementNode(STMT_ASSIGN);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                            $$->attr.op=TOKEN_ID;
                        }
                    |   ID TOKEN_LB expression TOKEN_RB TOKEN_ASSIGN expression
                        {   $$=newStatementNode(STMT_ASSIGN);
                            $$->child[0]=$1;
                            ($$->child[0])->child[0]=$3;
                            $$->child[1]=$6;
                            $$->attr.op=TOKEN_ARRAY;
                        }
                    |
                        ID TOKEN_DOT ID TOKEN_ASSIGN expression
                        {   $$=newStatementNode(STMT_ASSIGN);
                            $$->child[0]=$1;
                            ($$->child[0])->child[0]=$3;
                            $$->child[1]=$5;
                            $$->attr.op=TOKEN_RECORD;
                        }
                    ;
goto_stmt           :   TOKEN_GOTO  TOKEN_INT
                        {   $$=newStatementNode(STMT_GOTO);
                            $$->attr.val=atoi(tokenString);
                        }
                    ;
if_stmt             :   TOKEN_IF expression TOKEN_THEN stmt  else_clause
                        {   $$=newStatementNode(STMT_IF);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                            $$->child[2]=$5;
                        }
                    ;
else_clause         :   {
                            $$=NULL;
                        }
                    |   TOKEN_ELSE  stmt    {
                            $$=$2;
                        }
                    ;
repeat_stmt         :   TOKEN_REPEAT stmt_list TOKEN_UNTIL expression
                        {
                            $$=newStatementNode(STMT_REPEAT);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                        }
                    |
while_stmt          :   TOKEN_WHILE expression TOKEN_DO stmt
                        {   $$=newStatementNode(STMT_WHILE);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                        };
case_stmt           :   TOKEN_CASE expression TOKEN_OF case_expr_list TOKEN_END
                        {   $$=newStatementNode(STMT_CASE);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                        };
case_expr_list      :   case_expr_list  case_expr
                        {   YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$2;
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   case_expr   {
                            $$=$1;
                        }
                        ;
case_expr           :   const_value TOKEN_COLON stmt TOKEN_SEMI
                        {
                            $$=newExpNode(EXP_CASE);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        }
                    |   ID  TOKEN_COLON stmt TOKEN_SEMI
                        {
                            $$=newExpNode(EXP_CASE);
                            $$->child[0]=$1;
                            $$->child[1]=$3;
                        };
for_stmt            :   TOKEN_FOR ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO stmt
                        {
                            $$=newStatementNode(STMT_FOR);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                            $$->child[2]=$6;
                            $$->child[3]=$8;
                            $$->attr.op=TOKEN_TO;
                        }
                    |   TOKEN_FOR ID TOKEN_ASSIGN expression TOKEN_DOWNTO expression TOKEN_DO stmt
                        {
                            $$=newStatementNode(STMT_FOR);
                            $$->child[0]=$2;
                            $$->child[1]=$4;
                            $$->child[2]=$6;
                            $$->child[3]=$8;
                            $$->attr.op=TOKEN_DOWNTO;
                        };
proc_stmt           :   ID
                        {   $$=newStatementNode(STMT_PROC_ID);
                            $$->attr.name=copyString($1->attr.name);
                        }
                    |   ID TOKEN_LP args_list TOKEN_RP
                        {   $$=newStatementNode(STMT_PROC_ID);
                            $$->attr.name=copyString($1->attr.name);
                            $$->child[0]=$3;
                        }
                    |   TOKEN_READ TOKEN_LP factor TOKEN_RP
                        {
                            $$=newStatementNode(STMT_PROC_SYS);
                            $$->attr.op=TOKEN_READ;
                            $$->child[0]=$3;
                        }
                    |   TOKEN_WRITE TOKEN_LP args_list TOKEN_RP
                        {   $$=newStatementNode(STMT_PROC_SYS);
                            $$->attr.op=TOKEN_WRITE;
                            $$->child[0]=$3;
                        }
                    |   TOKEN_WRITELN
                        {   $$=newStatementNode(STMT_PROC_SYS);
                            $$->attr.op=TOKEN_WRITELN;
                        }
                    |   TOKEN_WRITELN TOKEN_LP args_list TOKEN_RP
                        {   $$=newStatementNode(STMT_PROC_SYS);
                            $$->attr.op=TOKEN_WRITELN;
                            $$->child[0]=$3;
                        }
                    ;
args_list           :   args_list TOKEN_COMMA expression
                        {   YYSTYPE t=$1;
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=$3;
                                $$=$1;
                            }
                            else
                                $$=$3;
                        }
                    |   expression  {
                            $$=$1;
                        }
                    ;

expression          :   expression TOKEN_GE expr {   
                            $$=newExpressionNode($1,$3,TOKEN_GE);
                        }
                    |   expression TOKEN_GT expr {   
                            $$=newExpressionNode($1,$3,TOKEN_GT);
                        }
                    |   expression TOKEN_LE expr {   
                            $$=newExpressionNode($1,$3,TOKEN_LE);
                        }
                    |   expression TOKEN_LT expr {   
                            $$=newExpressionNode($1,$3,TOKEN_LT);
                        }
                    |   expression TOKEN_EQUAL expr {   
                            $$=newExpressionNode($1,$3,TOKEN_EQUAL);
                        }
                    |   expression TOKEN_UNEQUAL expr {   
                            $$=newExpressionNode($1,$3,TOKEN_UNEQUAL);
                        }
                    |   expr {   
                            $$=$1;
                        } 
                    ;

expr                :   expr TOKEN_PLUS term  {   
                            $$=newExpressionNode($1,$3,TOKEN_PLUS);
                        }
                    |   expr TOKEN_MINUS term  {   
                            $$=newExpressionNode($1,$3,TOKEN_MINUS);
                        }
                    |   expr TOKEN_OR term  {   
                            $$=newExpressionNode($1,$3,TOKEN_OR);
                        }
                    |   term {   
                            $$=$1;
                        } 
                    ;

term                :   term TOKEN_MUL factor {   
                            $$=newExpressionNode($1,$3,TOKEN_MUL);
                        }
                    |   term TOKEN_DIV factor {   
                            $$=newExpressionNode($1,$3,TOKEN_DIV);
                        }
                    |   term TOKEN_MOD factor {   
                            $$=newExpressionNode($1,$3,TOKEN_MOD);
                        }
                    |   term TOKEN_AND factor {   
                            $$=newExpressionNode($1,$3,TOKEN_AND);
                        }
                    |   factor {
                            $$=$1;
                        } 
                    ;

factor              :   ID
                        {
                            $$=$1;
                        }
                    |   ID TOKEN_LP args_list TOKEN_RP
                        {   $$=newExpNode(EXP_FUNC_ID);
                            $$->attr.name=copyString($1->attr.name);
                            $$->child[0]=$3;
                        }
                    |   const_value {
                            $$=$1;
                        }
                    |   TOKEN_LP expression TOKEN_RP    {
                            $$=$2;
                        }
                    |   TOKEN_NOT factor
                        {   
                            $$=newExpressionNode($2,NULL,TOKEN_NOT);
                        }
                    |   TOKEN_MINUS   factor
                        {   
                            $$=newExpressionNode($2,NULL,TOKEN_MINUS);
                        }
                    |   ID TOKEN_LB expression TOKEN_RB
                        {   $$=$1;
                            $$->child[0]=$3;
                            $$->type=EXPTYPE_ARRAY;
                        }
                    |   ID TOKEN_DOT ID
                        {   $$=$1;
                            $$->child[0]=$3;
                            $$->type=EXPTYPE_RECORD;
                        }
                    |   TOKEN_ABS TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_ABS,$3);
                        }
                    |   TOKEN_CHR TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_CHR,$3);
                        }
                    |   TOKEN_ODD TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_ODD,$3);
                        }
                    |   TOKEN_ORD TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_ORD,$3);
                        }
                    |   TOKEN_PRED TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_PRED,$3);
                        }
                    |   TOKEN_SQR TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_SQR,$3);
                        }
                    |   TOKEN_SQRT TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_SQRT,$3);
                        }
                    |   TOKEN_SUCC TOKEN_LP args_list TOKEN_RP
                        {   
                            $$=newFuncSysExpNode(TOKEN_SUCC,$3);
                        }
                    ;
%%

TreeNode * parse(){
    yyparse();
    return myTree;
}
