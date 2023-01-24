#include <stdio.h>
#include "expr.h"
#include "stmt.h"
#include "util.h"


extern int yyparse();
extern Statement *parser_result;

void printPreamble(){
    printf("#include <stdio.h>\n");
    printf("#include <stdbool.h>\n");
    printf("int main (int *argc, char **argv){\n");
}

void printPostamble(){
    printf("}\n");
}

int main(int argc, char **argv){

    int rVal = yyparse();

    if (rVal == 0){
        printPreamble();
        Statement *cur = get_stmts();
        while(cur){
            printf("\t");
            printCodeForStatement(cur);
            cur = cur->next;
        }
        printf("\n");
        printPostamble();
    }else{
        printf("parse fail\n");
    }

    return rVal;

}