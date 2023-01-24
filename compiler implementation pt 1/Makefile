all: descent

descent: main_program.c
	gcc -o descent main_program.c parser_helpers.c recursive_descent.c 

test: all
	./descent 

submission: clean 
	tar -a -c -f thinh.zip * 

clean:
	$(RM) descent.exe a.exe *.zip