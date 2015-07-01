a.out : tiny.l tiny.y  CG.h analyze.h symtab.h util.cpp main.cpp
	flex tiny.l
	yacc -d tiny.y
	g++ -std=c++11 util.cpp lex.yy.c y.tab.c main.cpp CG.cpp analyze.cpp symtab.cpp -L "/usr/local/Cellar/flex/2.5.39/lib" -lfl -o a.out

clean :
	rm -f a.* 
	rm -f y.tab.*
	rm -f lex.*
	rm -f *.asm
