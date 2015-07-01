a.out : pas.l pas.y  code_generator.h analyze.h symbol_table.h util.cpp main.cpp
	flex pas.l
	yacc -d pas.y
	g++ -std=c++11 util.cpp lex.yy.c y.tab.c main.cpp code_generator.cpp analyze.cpp symbol_table.cpp -L "/usr/local/Cellar/flex/2.5.39/lib" -lfl -o a.out

clean :
	rm -f a.* 
	rm -f y.tab.*
	rm -f lex.*
	rm -f *.asm
