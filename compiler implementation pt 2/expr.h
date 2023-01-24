#ifndef __EXPR_H
#define __EXPR_H

#include <stdbool.h>

typedef enum e_expr{
    EXPR_ADD,
    EXPR_MINUS,
    EXPR_MULT,
    EXPR_DIV,
    EXPR_VALUE,
    EXPR_NAME,
    EXPR_LITERAL,
    EXPR_EQUALS, 
} ExpressionType;

typedef struct s_expr{
    ExpressionType kind;
    struct s_expr *left;
    struct s_expr *right;
    int value;
    const char *name;
    const char *literal;
    bool boolean;
} Expression;

extern Expression *createExpression(ExpressionType type, Expression *left, Expression *right);
extern Expression *createValue(int value);
extern int evaluateExpression(Expression *expression);
extern void printExpression(Expression *expression);
extern Expression *createName(const char *name);
extern Expression *createLiteral(const char *literal);
extern void printExpressionFormatSpecifier(Expression *expression);
extern Expression *createBoolean(bool boo);
#endif //__EXPR_H