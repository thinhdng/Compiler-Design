all: main.c scan.c parse.c wrap.c error.c expr.c decl.c stmt.c util.c
	gcc main.c scan.c parse.c wrap.c error.c expr.c decl.c stmt.c util.c -o compiler

parse.c: parse.y
	bison --defines=token.h --output=parse.c parse.y

scan.c: scan.l
	flex --header-file=scan.h --outfile=scan.c scan.l

test: simple
	./simple < input

test2: compiler 
	./compiler < input2

test3: compiler
	./compiler < input2 > generated.c
	gcc -o generated.c program

submission: all
	tar -a -c -f thinh.zip *

clean:
	$(RM) scan.h scan.c parse.c token.h generated.c program.exe *.zip