#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include "util.h"
#include "symtab.h"

#define OFFSET_INC 4


//var memory location
static int base = 0;
static int offset = 0;

/*trace*/
static int TraceAnalyze = 1;

/*error*/
static int Error = 0;

int buildSymtable(TreeNode* t);
void traverseTree(TreeNode* t);
void insertNode(TreeNode* t);

#endif
