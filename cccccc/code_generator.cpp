//
//  code_generator.cpp
//  cccccc
//
//  Created by 谭芃菲 on 15/6/20.
//  Copyright (c) 2015年 tpf. All rights reserved.
//

#include "code_generator.h"

FILE* codename = NULL;
FILE* dataname = NULL;
FILE* ff = NULL;

char tmp[200];

void CGExpOp(TreeNode* pnode){
    
	if (pnode->child[0]!=NULL && pnode->child[1]!=NULL) {
		GenerateCode(pnode->child[0]);
		OUTPUT("push eax\n");
	
		GenerateCode(pnode->child[1]);
		OUTPUT("push eax\n");


		if ((pnode->child[0])->RuningType != (pnode->child[1])->RuningType){
 			printf("Line %d, Error: Different data type can not be calculated.\n",pnode->lineno);
 			fflush(stdout);				
 		}
 		
		if ((pnode->child[0])->RuningType==EXPTYPE_REAL && (pnode->child[1])->RuningType==EXPTYPE_REAL)
			pnode->RuningType=EXPTYPE_REAL;
		if ((pnode->child[0])->RuningType==EXPTYPE_INT && (pnode->child[1])->RuningType==EXPTYPE_INT)
			pnode->RuningType=EXPTYPE_INT; 

	}
	else {
		OUTPUT("push 0\n");
		GenerateCode(pnode->child[0]);
		OUTPUT("push eax\n");
		pnode->RuningType=(pnode->child[0])->RuningType;
	}



	if (pnode->RuningType==EXPTYPE_INT){
		OUTPUT("pop ebx\n");
		OUTPUT("pop eax\n");
		switch(pnode->attr.op)
		{
		case TOKEN_PLUS:
			OUTPUT("add eax, ebx\n");
			break;
		case TOKEN_MINUS:
			OUTPUT("sub eax, ebx\n");
			break;
		case TOKEN_MUL:
			OUTPUT("xor edx, edx\nimul ebx\n");
			break;
		case TOKEN_DIV:
			OUTPUT("xor edx, edx\nidiv ebx\n");
			break;
		case TOKEN_MOD:
			OUTPUT("xor edx, edx\nidiv ebx\n");
			OUTPUT("mov eax,edx\n");
			break;
		case TOKEN_LT:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("setl al\n");
			break;
		case TOKEN_LE:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("setng al\n");
			break;
		case TOKEN_GT:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("setg al\n");
			break;
		case TOKEN_GE:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("setnl eax\n");
			break;
		case TOKEN_EQUAL:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("sete al\n");
			break;
		case TOKEN_UNEQUAL:
			OUTPUT("cmp eax, ebx\n");
			OUTPUT("mov eax, 0\n");
			OUTPUT("setne al\n");
			break;
		}	
	}
	else {
		OUTPUT("fld dword ptr [esp+4]\n");
		OUTPUT("fld dword ptr [esp]\n");
		OUTPUT("pop eax\n");
		OUTPUT("pop eax\n");
		switch(pnode->attr.op){
		case TOKEN_PLUS:
			OUTPUT("fadd\n");
			break;
		case TOKEN_MINUS:
			OUTPUT("fsub\n");
			break;
		case TOKEN_MUL:
			OUTPUT("fmul\n");
			break;
		case TOKEN_DIV:
			OUTPUT("fdiv\n");
			break;
		case TOKEN_LT:
			OUTPUT("fcom\n");
			break;
		case TOKEN_LE:
			OUTPUT("fcom\n");
			break;
		case TOKEN_GT:
			OUTPUT("fcom\n");
			break;
		case TOKEN_GE:
			OUTPUT("fcom\n");
			break;
		case TOKEN_EQUAL:
			OUTPUT("fcom\n");
			break;
		}
		OUTPUT("sub esp,4\n");
		OUTPUT("fstp dword ptr [esp]\n");
		OUTPUT("pop eax\n");
		
	}
}



void CGExpId(TreeNode* pnode){
	
	int level;
	int offset;
	int lower = 0;
	ExpType cgtype;
	LookupRet st_var;

	VariableList ssvar=findVarList(pnode->attr.name);
 	if (ssvar==NULL){
 		printf("Error in Line %d: Variable not existed.\n",pnode->lineno);
 		fflush(stdout);
 	}

 	cgtype=ssvar->type;

	if (cgtype==EXPTYPE_ARRAY){  // array type

		if (ssvar->pAttr==NULL){
 			printf("Error in Line %d: not an array.\n",pnode->lineno);
 			fflush(stdout);
 		}

		lower=(((ArrayDef)ssvar->pAttr)->subBound)->LowerBound.i;
		level=ssvar->memloc.baseLoc;
		offset=ssvar->memloc.offset;

	}
	else if (cgtype==EXPTYPE_RECORD){ // record {int real bool char}
		st_var=findRecord(pnode->attr.name,(pnode->child[0])->attr.name);
		level=st_var.jumpLevel;
		offset=st_var.totalOff;
	}
	else {	 //int real bool char
		level=ssvar->memloc.baseLoc;
		offset=ssvar->memloc.offset;
	}

	if (cgtype==EXPTYPE_ARRAY){
		CGNodeExpression(pnode->child[0]);
		sprintf(tmp,"mov ebx, %d\n", lower);
		OUTPUT(tmp);	

		OUTPUT("sub eax, ebx\n");
		OUTPUT("mov ebx, 4\n");
		OUTPUT("imul eax,ebx\n");
		sprintf(tmp,"mov edi, %d\n",offset);
		OUTPUT(tmp);
		OUTPUT("add edi, eax\n");
	}
	else {
		sprintf(tmp, "mov edi, %d\n", offset);
		OUTPUT(tmp);	
	}

	if (cgtype==EXPTYPE_ARRAY){ 
		cgtype=((ArrayDef)ssvar->pAttr)->arrayType;
	}
	else if (cgtype==EXPTYPE_RECORD){
		cgtype=st_var.type;	
	}		
	OUTPUT("mov esi, ecx\n");
	while (level){
		OUTPUT("mov eax, [esi]\n");
		OUTPUT("mov esi, eax\n");
		level=level-1;
	}
	OUTPUT("add esi, edi\n");


	if (cgtype==EXPTYPE_INT || cgtype==EXPTYPE_CHAR || cgtype==EXPTYPE_BOOL){
		OUTPUT("mov eax, [esi]; calculate ExpId \n");
		pnode->RuningType=EXPTYPE_INT;
		//printf("EXPTYPE_INT\n");
	}
	else if (cgtype==EXPTYPE_REAL){
		OUTPUT("mov eax, dword ptr [esi]\n"); 
		pnode->RuningType=EXPTYPE_REAL;
		//printf("EXPTYPE_REAL\n");
	}

}

void CGExpConst(TreeNode* pnode){
	char const_real_data[100];	

	switch (pnode->type){
		case EXPTYPE_INT:
			sprintf(tmp, "mov eax, %d; calculate int ExpConst \n", pnode->attr.val);
			OUTPUT(tmp);
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_CHAR:
			sprintf(tmp, "mov eax, %d; calculate char ExpConst \n", pnode->attr.char_val);
			OUTPUT(tmp);
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_BOOL:
			sprintf(tmp, "mov eax, %d; calculate bool ExpConst \n", pnode->attr.val);
			OUTPUT(tmp);
			pnode->RuningType=EXPTYPE_INT;
			break;
		case EXPTYPE_REAL:
			strcpy(const_real_data, GetLabel_data());	
			sprintf(tmp, "%s dd %lf\n",const_real_data, pnode->attr.real_val);
		    OUTPUT_DATA(tmp);
        	sprintf(tmp,"mov eax, dword ptr[%s]; calculate real ExpConst \n",const_real_data);
        	OUTPUT(tmp);
        	pnode->RuningType=EXPTYPE_REAL;
			break;
        default:
            break;
	}
}


void CGPopParam(TreeNode* pnode,SimpleTypeList judge_var){
	
	if (pnode==NULL || judge_var==NULL)
		return;

	if (judge_var->isVar==1){
		CGNodeExpression(pnode);
		OUTPUT("pop eax\n");
		OUTPUT("mov [esi],eax\n");
	}
	else OUTPUT("pop eax\n");

	CGPopParam(pnode->sibling,judge_var->next);
}

void CGPushParam(TreeNode* pnode){
	if (pnode->sibling!=NULL){
		CGPushParam(pnode->sibling);
	}

	CGNodeExpression(pnode);
	OUTPUT("push eax\n");

}

void CGExpFunc(TreeNode* pnode){

	FuncList judge_var=findFuncList(pnode->attr.name);

	OUTPUT("push eax\n;return value");  //return value push	

	CGPushParam(pnode->child[0]);


	OUTPUT("push ecx\n");  // access link
	OUTPUT("mov ecx, esp\n");

	sprintf(tmp, "call %s\n", pnode->attr.name);
	OUTPUT(tmp);

	OUTPUT("pop ecx\n");


	CGPopParam(pnode->child[0],judge_var->paraList);

	OUTPUT("pop eax\n;return value");  //return value 

}


void CGStmtProc(TreeNode* pnode){

	ProcList judge_var=findProcList(pnode->attr.name);

	CGPushParam(pnode->child[0]);


	OUTPUT("push ecx\n;access link");  // save access link
	OUTPUT("mov ecx, esp\n");

	sprintf(tmp, "call %s\n", pnode->attr.name);
	OUTPUT(tmp);

	OUTPUT("pop ecx\n");//pop 

	CGPopParam(pnode->child[0],judge_var->paraList);
}



void CGStmtAssign(TreeNode* pnode){


		GenerateCode(pnode->child[1]);
		OUTPUT("push eax\n");
		VariableList ssvar=findVarList((pnode->child[0])->attr.name);
		if (ssvar->isConst){		
 			printf("Line %d, Error: The const variable %s can not be assigned.\n",pnode->lineno,(pnode->child[0])->attr.name);
 			fflush(stdout);	
		}
		GenerateCode(pnode->child[0]);
		OUTPUT("pop eax\n");
		OUTPUT("mov [esi-0], eax; assign\n");
	
}

char* GetLabel()
{
	static int count = 0;
	static char label[2000];
	char tp[2000];
	strcpy(label, "___label");
	sprintf(tp, "%d", count);
	strcat(label, tp);
	count++;
	return label;
}

char* GetLabel_sys(int val)
{
	char tmp2[1024];
	static char label[1024];
	strcpy(label, "___sys_label");
	sprintf(tmp2, "%d", val);
	strcat(label, tmp2);
	return label;
}

char* GetLabel_data(){
    static int datalabel_cnt = 0;
    char tmp[100];
    static char datalabel[200];
    strcpy(datalabel,"_REALNUM");
    sprintf(tmp,"%d",datalabel_cnt);
    strcat(datalabel,tmp);
    datalabel_cnt++;
    return datalabel;
}


void CGStmtLabel(TreeNode* pnode){
	char sys_label[100];
	strcpy(sys_label, GetLabel_sys(pnode->attr.val));
	sprintf(tmp, "%s:\n", sys_label); 
	OUTPUT(tmp);	
	GenerateCode(pnode->child[0]);
}

void CGStmtGoto(TreeNode* pnode){
	char sys_label[100];
	strcpy(sys_label, GetLabel_sys(pnode->attr.val));
	sprintf(tmp, "jmp %s\n", sys_label); 
	OUTPUT(tmp);		
}


void CGStmtCase(TreeNode* pnode){

	char case_end[100];	
	strcpy(case_end, GetLabel());	

	GenerateCode(pnode->child[0]);
	OUTPUT("push eax\n");
	GenerateCode(pnode->child[1]);

}

void CGExpCase(TreeNode* pnode){

	char case_end[100];	
	strcpy(case_end, GetLabel());	

	GenerateCode(pnode->child[0]);
	
	OUTPUT("pop ebx\n");
	OUTPUT("cmp ebx,eax\n");

	sprintf(tmp, "jne %s\n", case_end);  
	OUTPUT(tmp);

	GenerateCode(pnode->child[1]);

	sprintf(tmp, "%s:\n", case_end);
	OUTPUT(tmp);
	if (pnode->sibling!=NULL)
		OUTPUT("push ebx\n");
}

void CGStmtWhile(TreeNode* pnode){
	char while_start[100], while_end[100];
	strcpy(while_start, GetLabel());
	strcpy(while_end, GetLabel());	


	sprintf(tmp, "%s:\n", while_start);
	OUTPUT(tmp);

	GenerateCode(pnode->child[0]);

	OUTPUT("cmp eax, 0\n");
	sprintf(tmp,"je %s\n",while_end);
	OUTPUT(tmp);

	GenerateCode(pnode->child[1]);
	sprintf(tmp,"jmp %s\n",while_start);
	OUTPUT(tmp);
	sprintf(tmp, "%s:\n", while_end);
	OUTPUT(tmp);
}


void CGStmtRepeat(TreeNode* pnode){
	char start[100];
	strcpy(start, GetLabel());
	
	sprintf(tmp,"%s:\n",start);
	OUTPUT(tmp);	

	GenerateCode(pnode->child[0]);
	GenerateCode(pnode->child[1]);

	OUTPUT("cmp eax, 0\n");
	sprintf(tmp,"je %s\n",start);
	OUTPUT(tmp);
	
}

void CGStmtFor(TreeNode* pnode){

	char for_start[100], for_end[100];
	strcpy(for_start, GetLabel());
	strcpy(for_end, GetLabel());

	GenerateCode(pnode->child[1]);
	OUTPUT("push eax\n");
	GenerateCode(pnode->child[0]);
	OUTPUT("pop eax\n");
	OUTPUT("mov [esi-0],eax  \n");

    // cg loop
	if(pnode->attr.op == TOKEN_TO){
        // to
		sprintf(tmp,"%s:\n",for_start);
		OUTPUT(tmp);	
		GenerateCode(pnode->child[2]);
		OUTPUT("push eax\n");
		GenerateCode(pnode->child[0]);
		OUTPUT("pop ebx\n");	
		OUTPUT("cmp eax, ebx\n");
		sprintf(tmp, "ja %s\n", for_end);
		OUTPUT(tmp);	

		GenerateCode(pnode->child[3]);
		GenerateCode(pnode->child[0]);
		OUTPUT("inc eax\n");
		OUTPUT("mov [esi-0],eax\n");	

		sprintf(tmp,"jmp %s\n",for_start);
		OUTPUT(tmp);	
		sprintf(tmp,"%s:\n",for_end);
		OUTPUT(tmp);	
	}
	 else {
        // downto
		sprintf(tmp,"%s:\n",for_start);
		OUTPUT(tmp);	
		GenerateCode(pnode->child[2]);
		OUTPUT("push eax\n");
		GenerateCode(pnode->child[0]);
		OUTPUT("pop ebx\n");	
		OUTPUT("cmp eax, ebx\n");
		sprintf(tmp, "jb %s\n", for_end);
		OUTPUT(tmp);	

		GenerateCode(pnode->child[3]);
		GenerateCode(pnode->child[0]);
		OUTPUT("dec eax\n");
		OUTPUT("mov [esi-0],eax\n");	
		
		sprintf(tmp,"jmp %s\n",for_start);
		OUTPUT(tmp);	
		sprintf(tmp,"%s:\n",for_end);
		OUTPUT(tmp);	
	 }
}



void CGStmtIf(TreeNode* pnode){
	char if_label[100], else_label[100], exit_label[100];
	strcpy(if_label, GetLabel());
	strcpy(else_label, GetLabel());
	strcpy(exit_label, GetLabel());
	
	//if
	GenerateCode(pnode->child[0]);
	OUTPUT("cmp eax, 1\n");	
	sprintf(tmp, "je %s \njmp %s\n", if_label, else_label);
	OUTPUT(tmp);	
	
	//if-part
	sprintf(tmp,"%s:\n",if_label);
	OUTPUT(tmp);	
	GenerateCode(pnode->child[1]);

	sprintf(tmp,"jmp %s\n",exit_label);	
	OUTPUT(tmp);	

	sprintf(tmp, "%s: \n", else_label);
  	OUTPUT(tmp);	

	if (pnode->child[2]!=NULL)
		GenerateCode(pnode->child[2]);
	
	sprintf(tmp, "%s: \n", exit_label);
  	OUTPUT(tmp);				
}

void GStmtOutput(TreeNode* pnode){
	TreeNode *node = pnode->child[0];
	while (node!=NULL){
		CGNodeExpression(node);
        switch(node->RuningType){
            case EXPTYPE_REAL:
            OUTPUT("pusha\n");
			OUTPUT("push eax\n");
			OUTPUT("fld dword ptr [esp]\n");
			OUTPUT("sub esp, 4\n");
			OUTPUT("fstp qword ptr [esp]\n");
			if(pnode->attr.op==TOKEN_WRITELN){
				OUTPUT("push offset lb_writeln_real\n");
			}
			else if(pnode->attr.op==TOKEN_WRITE){
				OUTPUT("push offset lb_write_real\n");
			}
			OUTPUT("call printf\n");
			OUTPUT("add esp, 8\n");
			OUTPUT("pop eax\n");
			OUTPUT("popa\n");
            break;
            case EXPTYPE_INT:
            OUTPUT("pusha\n");
            if(pnode->attr.op==TOKEN_WRITELN){
				OUTPUT("push offset lb_writeln_real\n");
			}
			else if(pnode->attr.op==TOKEN_WRITE){
				OUTPUT("push offset lb_write_real\n");
			}
            OUTPUT("popa\n");
            break;
            default:
                break;
        }
		node=node->sibling;
	}
}


void GStmtInput(TreeNode* pnode){
	TreeNode *node=NULL;
	char total[100];
	const char* kind_real= "real, addr lb_tmp\n";
	const char* kind_int="int, addr lb_tmp\n";
	const char * out="invoke crt_scanf, addr lb_read_";
	total[0]=0;

	node=pnode->child[0];
	while(node!=NULL){
        CGNodeExpression(node);
        strcpy(total,out);
        switch(node->RuningType){
            case EXPTYPE_REAL://real
                strcat(total,kind_real);
                break;
            case EXPTYPE_INT://int
                strcat(total,kind_int);
                break;
            default:
                break;
        }
		OUTPUT("pusha\n");
		OUTPUT(total);
		OUTPUT("popa\n");
		OUTPUT("mov eax, dword ptr lb_tmp\n");
		OUTPUT("mov [esi], eax\n");
		node=node->sibling;
	}
}


void CGNodeExpression(TreeNode* pnode){
	switch (pnode->kind.exp){
        case EXP_ID:
            CGExpId(pnode);
            break;
        case EXP_OP:
            CGExpOp(pnode);
            break;
        case EXP_CONST:
            CGExpConst(pnode);
            break;
        case EXP_CASE:
            CGExpCase(pnode);
            break;
        case EXP_FUNC_ID:
            CGExpFunc(pnode);
            break;
        default:
            break;
    }
}
void Write_Read(TreeNode* pnode){
    if(pnode->attr.op==TOKEN_WRITE)
        GStmtOutput(pnode);//Write
    else if(pnode->attr.op==TOKEN_READ)
        GStmtInput(pnode);//read
    else if(pnode->attr.op==TOKEN_WRITELN)
        GStmtOutput(pnode);
}

void GenerateCode(TreeNode* pnode){
	int size_param;
	switch (pnode->nodekind){
		case NODE_STATEMENT:
			switch (pnode->kind.stmt){
				case STMT_ASSIGN:
					CGStmtAssign(pnode);
					break;
				case STMT_IF:
					CGStmtIf(pnode);
					break;
				case STMT_FOR:
					CGStmtFor(pnode);
					break;
				case STMT_WHILE:
					CGStmtWhile(pnode);
					break;
				case STMT_REPEAT:
					CGStmtRepeat(pnode);
					break;	
				case STMT_CASE:
					CGStmtCase(pnode);
					break;	
				case STMT_GOTO:
					CGStmtGoto(pnode);
					break;	
				case STMT_LABEL:
					CGStmtLabel(pnode);
					break;	
				case STMT_PROC_ID:
					CGStmtProc(pnode);
					break;
				case STMT_PROC_SYS:
					Write_Read(pnode);
                    break;
				
			}
			break;
		case NODE_EXPRESSION:
				CGNodeExpression(pnode);
			break;
		case NODE_DECLARE:
			switch (pnode->kind.decl){
				case DECL_ROUTINEHEAD:
					size_param=enterNewScope(pnode);

					if (pnode->child[3]!=NULL)
  						GenerateCode(pnode->child[3]);
								
					if (strcmp(pnode->attr.name,"main")){
						sprintf(tmp, "%s: \n",pnode->attr.name);
						OUTPUT(tmp);
					}
					else {
						OUTPUT("main PROC\n");
						OUTPUT("mov ecx, esp\n");
					}
  					sprintf(tmp, "sub esp, %d\n", size_param);
  					OUTPUT(tmp);
  					break;
				case DECL_FUNCTION:
					funcListInsert(pnode->child[0]);
					(pnode->child[1])->attr.name=(pnode->child[0])->attr.name;
					GenerateCode(pnode->child[1]);
                    //routine_head
					
					size_param=leaveScope();
					sprintf(tmp, "add esp, %d\n", size_param);
  					OUTPUT(tmp);	
					OUTPUT("ret\n");
					break;
    			case DECL_PROCEDURE:
					fflush(stdout);
					procListInsert(pnode->child[0]);
					(pnode->child[1])->attr.name=(pnode->child[0])->attr.name;
					GenerateCode(pnode->child[1]);
                    //routine_head
				
					size_param=leaveScope();
					sprintf(tmp, "add esp, %d\n", size_param);
  					OUTPUT(tmp);	
					OUTPUT("ret\n");
					break;
                default:
                    break;
			}
			break;
		case NODE_TYPE:
			break;
		default: printf("pnode->nodekind Default");
	}
	if(pnode->sibling!=NULL){
		GenerateCode(pnode->sibling);	
	}
	
}

int CGAsm(TreeNode* pnode,char * ffname){
	int size_param;
	char buf[10000];

	codename = fopen("code_part.asm", "w");
	dataname = fopen("data_part.asm", "w");
	
	OUTPUT_DATA(".386\n");
	OUTPUT_DATA(".model flat,stdcall\n");
	OUTPUT_DATA("option casemap:none\n");
	OUTPUT_DATA("include masm32\\include\\msvcrt.inc\n");
	OUTPUT_DATA("includelib msvcrt.lib\n");

	OUTPUT_DATA("printf  proto C:dword,:dword\n");

	OUTPUT_DATA(".data\n");
	OUTPUT_DATA("lb_write_int db '%d',0\n");
	OUTPUT_DATA("lb_writeln_int db '%d',0ah,0dh,0\n");
	OUTPUT_DATA("lb_write_real db '%lf',0\n");
	OUTPUT_DATA("lb_writeln_real db '%lf',0ah,0dh,0\n");
	OUTPUT_DATA("lb_tmp db 0, 0, 0, 0, 0, 0, 0, 0\n");
	OUTPUT_DATA("lb_read_int db '%d',0\n");
	OUTPUT_DATA("lb_read_real db '%f',0\n");

	OUTPUT(".code\n");	
	
	initScope();
	char attrName[] = "main";
	pnode->attr.name = attrName;
	GenerateCode(pnode);
	

	size_param=leaveScope();
	sprintf(tmp, "add esp, %d\n", size_param);
  	OUTPUT(tmp);	
	OUTPUT("main ENDP\n");
	OUTPUT("END main\n");
	fclose(codename);
	fclose(dataname);
	

	ff = fopen(ffname, "w");
	codename = fopen("code_part.asm", "r");
	dataname = fopen("data_part.asm", "r");	
	while(fgets(buf,BUFSIZ,dataname)!=NULL){
		fputs(buf,ff);
	}
	while(fgets(buf,BUFSIZ,codename)!=NULL){
		fputs(buf,ff);
	}	
	fclose(codename);
	fclose(dataname);
	fclose(ff);
    
    return 0;
}
