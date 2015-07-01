#ifndef _CG_H_
#define _CG_H_

#include "util.h"
#include "y.tab.h"
#include "analyze.h"
#include "symtab.h"


#define CG_OUTPUT(asm) fprintf(codename, "%s", asm);
#define CG_OUTPUT_DATA(asm) fprintf(dataname, "%s", asm);

int CG_main(TreeNode* pnode,char * ffname);

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
void GenerateCode(TreeNode* pnode);

#endif
