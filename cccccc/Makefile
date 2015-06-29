a.out : tiny.l tiny.y global.h scan.h parse.h CG.h analyze.h symtab.h util.c main.c
	flex tiny.l
	yacc -d tiny.y
	g++ -std=c++11 util.c lex.yy.c y.tab.c main.c CG.c analyze.c symtab.cpp -L "/usr/local/Cellar/flex/2.5.39/lib" -lfl -o a.out
