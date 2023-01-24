#include "expr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Expression *createExpression(ExpressionType kind, Expression *left, Expression *right){
    Expression *expression = malloc(sizeof(Expression));
    
    expression->kind = kind;
    expression->left = left;
    expression->right = right;
    expression->value = 0;
    expression->name = NULL;
    expression->literal = NULL;
    expression->boolean = false;
    return expression;
}

Expression *createValue(int value){

    Expression *expression = createExpression(EXPR_VALUE, NULL, NULL);
    expression->value = value;
    return expression;

}

int evaluateExpression(Expression *expression){
    
    if (expression == NULL) return 0;

    int left = evaluateExpression(expression->left);
    int right = evaluateExpression(expression->right);

    switch(expression->kind){
        case EXPR_ADD:
            return left + right;
        case EXPR_MINUS:
            return left - right;
        case EXPR_MULT:
            return left * right;
        case EXPR_DIV:
            if(right == 0){
                printf("error: divide by 0\n");
                return -1;
            }else{
                return left / right;
            }
        case EXPR_VALUE:
            return expression->value;
        case EXPR_NAME:
        case EXPR_LITERAL:
            return 0;
        case EXPR_EQUALS:
            return left == right;
    }

    return 0;
}

void printExpressionFormatSpecifier(Expression *expression){
    if(expression == NULL) return;
    
    switch(expression->kind){
        case EXPR_LITERAL:
            printf("%%s");
            break;
        default:
            printf("%%d");
            break;
    }
}

void printExpression(Expression *expression){

    if(expression == NULL) return;

    //printf("(");

    printExpression(expression->left);
    
    switch(expression->kind){
        case EXPR_ADD:
            printf("+");
            break;
        case EXPR_MINUS:
            printf("-");
            break;
        case EXPR_MULT:
            printf("*");
            break;
        case EXPR_DIV:
            printf("/");
            break;
        case EXPR_VALUE:
            printf("%d", expression->value);
            break;
        case EXPR_NAME:
            printf("%s", expression->name);
            break;
        case EXPR_LITERAL:
            printf("%s", expression->literal);
            break;
        case EXPR_EQUALS:
            printf("==");
            break;
    }
    
    printExpression(expression->right);

    //printf(")");

}

Expression *createName(const char *name){

    Expression *expression = createExpression(EXPR_NAME, NULL, NULL);
    expression->name = name;
    return expression;
}

Expression *createLiteral(const char *literal){
    Expression *expression = createExpression(EXPR_LITERAL, NULL, NULL);
    expression->literal = literal;
    return expression;
}

Expression *createBoolean(bool boo){
    Expression *expression = createExpression(EXPR_EQUALS, NULL, NULL);
    expression->boolean = boo;
    return expression;
}