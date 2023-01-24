#ifndef TOKEN_TYPE__H
#define TOKEN_TYPE__H

typedef enum t_token{
    TOKEN_EOF,
    TOKEN_PLUS,
    TOKEN_MULTIPLY,
    TOKEN_IDENTIFIER,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN
} Token;

#endif // TOKEN_TYPE__H