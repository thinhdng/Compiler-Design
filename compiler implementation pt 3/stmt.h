#ifndef __STATEMENT_H
#define __STATEMENT_H

#include "decl.h"
#include "expr.h"

typedef enum e_statementkind{

    ESK_DECL,
    ESK_EXPR,
    ESK_IFELSE,
    ESK_FOR,
    ESK_PRINT,
    ESK_RETURN,
    ESK_BLOCK,

} EStatementKind;

typedef struct t_statement{

    EStatementKind kind;
    struct t_decl *declaration;
    Expression *initial_expression;
    Expression *expression;
    Expression *next_expression;
    struct t_statement *body;
    struct t_statement *else_body;
    struct t_statement *next;

} Statement;

extern Statement *createStatement(EStatementKind kind, struct t_decl *declaration, Expression *initial_expression, Expression *expression, Expression *next_expression, Statement *body, Statement *else_body, Statement *next);

extern Statement *createExpressionStatement(Expression *expression);
extern Statement *createPrintStatement(Expression *expression);
extern Statement *createIfStatement(Expression *expression);
extern void printStatement(Statement *Statement);
extern void printCodeForStatement(Statement *statement);
#endif // __STATEMENT_H