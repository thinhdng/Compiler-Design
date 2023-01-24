#ifndef PARSER_HELPERS__H
#define PARSER_HELPERS__H
#include "parser_helpers.h"
#include "token_type.h"

//src token buffer ptr, and how many tokens there are
extern void setupTokenBuffer(Token *srcTokenBuffer, int count);
extern void cleanupTokenBuffer();
extern Token scanToken();
extern void putBackToken(Token t);
extern int expectToken(Token t);

#endif // PARSER_HELPERS__H