#include <stdio.h>
#include "token_type.h"
#include "parser_helpers.h"
#include "recursive_descent.h"

int main(int argc, char **argv) {
	//Token list for 3*(4+5)
	Token buf[] = {TOKEN_IDENTIFIER, TOKEN_MULTIPLY, TOKEN_LEFT_PAREN, TOKEN_IDENTIFIER, TOKEN_PLUS, TOKEN_IDENTIFIER, TOKEN_RIGHT_PAREN, TOKEN_EOF};
	setupTokenBuffer(buf, sizeof(buf)/sizeof(buf[0]));
	int rVal = parse_P();
	cleanupTokenBuffer();

	printf("parsing the tokens gave a result of %d\n", rVal);

	return !rVal;

}