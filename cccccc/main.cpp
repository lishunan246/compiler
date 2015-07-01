//
//  main.cpp
//  cccccc
//
//  Created by 张鹏程 on 15/6/20.
//  Copyright (c) 2015年 amrzs. All rights reserved.
//

#include "util.h"
#include "code_generator.h"
#include "symtab.h"
#include "analyze.h"
#include <iostream>
#include <string>
using namespace std;

FILE * source;
bool traceLine = true;
int lineno=0;
TreeNode * parse(void);

int main(int argc, char const *argv[])
{
	char filename[] = "test.pas";
	char asmFileName[] = "out.asm";

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
    CG_main(syntaxTree, asmFileName);

    return 0;
}
