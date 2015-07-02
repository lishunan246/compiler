//
//  code_generator.h
//  cccccc
//
//  Created by 谭芃菲 on 15/6/20.
//  Copyright (c) 2015年 tpf. All rights reserved.
//


#ifndef _CODE_GENERATOR_H_
#define _CODE_GENERATOR_H_

#include "util.h"
#include "y.tab.h"
#include "analyze.h"
#include "symbol_table.h"


#define OUTPUT(asm) fprintf(codename, "%s", asm);
#define OUTPUT_DATA(asm) fprintf(dataname, "%s", asm);

/*inline Code_Out(char* in){
    fprintf(codename, "%s", in);
}
inline Data_Out(char* in){
    fprintf(dataname, "%s", in)
}*/


void CGExpOp(TreeNode* pnode);
void CGExpId(TreeNode* pnode);
void CGExpConst(TreeNode* pnode);
void CGExpCase(TreeNode* pnode);

char* GetLabel();
char* GetLabel_sys(int val);
char* GetLabel_data();

void CGPopParam(TreeNode* pnode,SimpleTypeList judge_var);
void CGPushParam(TreeNode* pnode);
void CGExpFunc(TreeNode* pnode);
void CGStmtProc(TreeNode* pnode);
void CGDeclFunction(TreeNode* pnode);
void CGDeclProcedure(TreeNode* pnode);


void CGStmtAssign(TreeNode* pnode);
void CGStmtFor(TreeNode* pnode);
void CGStmtIf(TreeNode* pnode);
void CGStmtRepeat(TreeNode* pnode);
void CGStmtWhile(TreeNode* pnode);
void CGStmtLabel(TreeNode* pnode);
void CGStmtCase(TreeNode* pnode);

void GStmtOutput(TreeNode* pnode);
void GStmtInput(TreeNode* pnode);
void CGNodeExpression(TreeNode* pnode);
void Write_Read(TreeNode* pnode);
void GenerateCode(TreeNode* pnode);

int CGAsm(TreeNode* pnode,char * ffname);

#endif
