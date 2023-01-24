%{

#include <stdio.h>
#include <stdlib.h>
#include "scan.h"
#include "expr.h"
#include "stmt.h"
#include "util.h"

int yylex();
void yyerror(const char *s);

#define YYSTYPE void*

Statement *parser_result = NULL;


%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_PRINT
%token TOKEN_STRING
%token TOKEN_EQUALS
%token TOKEN_IFELSE
%%

program:    statements            { parser_result = $1; }
       ;

statements: statement             {$$ = $1; append_stmt($1); }
        |statements statement     {$$ = $2; append_stmt($2); }
        ;

statement: expr TOKEN_SEMI          { $$ = createStatement(ESK_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
        | TOKEN_PRINT TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI {$$ = createPrintStatement($3);}
        | TOKEN_IFELSE TOKEN_LPAREN expr TOKEN_RPAREN {$$ = createIfStatement($3);}
        ;

expr: expr TOKEN_PLUS term          { $$ = createExpression(EXPR_ADD, $1, $3); }
    | expr TOKEN_MINUS term         { $$ = createExpression(EXPR_MINUS, $1, $3); }
    | TOKEN_STRING                  { $$ = createLiteral(scanned_text); }
    | expr TOKEN_DIV term           { $$ = createExpression(EXPR_DIV, $1, $3); }
    | expr TOKEN_EQUALS term       { $$ = createExpression(EXPR_EQUALS, $1, $3);}  
    | term                          { $$ = $1; }
    ;

term: factor                        { $$ = $1; }
    | term TOKEN_MULT factor        { $$ = createExpression(EXPR_MULT, $1, $3); }
    ;                                   

factor: TOKEN_INT                   { $$ = createValue(atoi(yytext)); }
      ;



%%