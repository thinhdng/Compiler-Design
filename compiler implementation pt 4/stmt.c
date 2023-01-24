#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#include "stmt.h"
#include "expr.h"
void printStatement(Statement *statement){

    if(statement == NULL) return;

    switch(statement->kind){
        case ESK_EXPR:
            printExpression(statement->expression);
            break;
        case ESK_PRINT:
            printf("show[");
            printExpression(statement->expression);
            printf("\n]");
            break;
       case ESK_IFELSE:
            printf("if(");
            printExpression(statement->expression);
            printf("\n):");
            break;
        default:
            break;

    }

}
Statement *createStatement(EStatementKind kind, struct t_decl *declaration, Expression *initial_expression, Expression *expression, Expression *next_expression, Statement *body, Statement *else_body, Statement *next){
    Statement *node = malloc(sizeof(Statement));
    node->kind = kind;
    node->declaration = declaration;
    node->initial_expression = initial_expression;
    node->expression = expression;
    node->next_expression = next_expression;
    node->body = body;
    node->else_body = body;
    node->next = next;
    return node;
}

Statement *createExpressionStatement(Expression *expression){
    return createStatement(ESK_EXPR, NULL, NULL, expression, NULL, NULL, NULL, NULL);
}

Statement *createPrintStatement(Expression *expression){
    return createStatement(ESK_PRINT, NULL, NULL, expression, NULL, NULL, NULL, NULL);
}

Statement *createIfStatement(Expression *expression){
    return createStatement(ESK_IFELSE, NULL, NULL, expression, NULL, NULL, NULL, NULL);
}
void printCodeForStatement(Statement *statement){
    switch(statement->kind){       
         case ESK_PRINT:
            printf("printf(\"");
            //get the type from expression
            printExpressionFormatSpecifier(statement->expression);
            printf("\\n\", ");
            printExpression(statement->expression);
            printf(");\n");
            break;
        case ESK_IFELSE:
            printf("if(");
            printExpression(statement->expression);
            printf(")\n");
            printf("{\n");
            //insert true body here

            printf("}\n");
            break;
        default:
            printExpression(statement->expression);
    }
}