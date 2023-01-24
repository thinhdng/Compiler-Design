#include <stdlib.h>
#include <string.h>
#include "parser_helpers.h"
#include "token_type.h"

static Token *token_buffer; //allocated memory
static Token *curr_token; //working ptr

//src token buffer ptr, and how many tokens there are
void setupTokenBuffer(Token *srcTokenBuffer, int count){
    token_buffer = (Token *)malloc(count * sizeof(Token));
    //memcpy(destination, source, amount of memory)
    memcpy(token_buffer, srcTokenBuffer, count *sizeof(Token));
    curr_token = token_buffer;
}

void cleanupTokenBuffer(){
    free(token_buffer);
    token_buffer = NULL;
    curr_token = NULL;
}

Token scanToken(){
    //get the curr token, and adv ptr for future use, a bit verbose
    Token t = *curr_token;
    curr_token++;
    return t;

    //return *curr_token++; do the same as above 3 lines but more confusing to understand if unfamiliar
}

void putBackToken(Token t){
    //move the ptr back a step, and then set the value of its contents
    --curr_token;
    *curr_token = t;
}

int expectToken(Token t){
    //check if the current token matches. if it does, adv and return true! 
    if (*curr_token == t){
        ++curr_token;
        return 1;
    }
    return 0;
}