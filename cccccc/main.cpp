#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "CG.h"
#include "symtab.h"
#include "analyze.h"
#include <iostream>

using namespace std;
char filename[30] = "test2";
FILE * source;
bool TraceScan = true;
int lineno=0;
TreeNode * parse(void);

int main(int argc, char const *argv[])
{
	if(argc==2)
	{
		cout<<"Opening: "<<argv[1]<<endl;
		source = fopen(argv[1],"r");
		if(!source)
		{
			cout<<"cannot open file"<<endl;
			return 1;
		}
	}
	else if(argc==1)
	{
		source = fopen(filename,"r");		
	}
	else
	{
		cout<<"param too much"<<endl;
		return 1;
	}

    TreeNode * syntaxTree;
    syntaxTree = parse();
    printTree(syntaxTree);
	CG_main(syntaxTree, "out.asm");

    return 0;
}
