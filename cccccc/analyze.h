#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include "util.h"
#include "symbol_table.h"

#define OFFSET_INC 4

//var memory location
static int base = 0;
static int offset = 0;

static int TraceAnalyze = 1;
static int Error = 0;

int buildSymtable(TreeNode* t);
void traverseTree(TreeNode* t);
void insertNode(TreeNode* t);

#endif
