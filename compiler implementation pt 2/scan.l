%{

#include "token.h"
#include "util.h"

%}

%%

[[:digit:]]+   {return TOKEN_INT;}
\+             {return TOKEN_PLUS;}
\-             {return TOKEN_MINUS;}
\;             {return TOKEN_SEMI;}
\*             {return TOKEN_MULT;}
\/             {return TOKEN_DIV;}
show          {return TOKEN_PRINT;}
if             {return TOKEN_IFELSE;}
\".*\"         {append_scan(yytext); return TOKEN_STRING;}
\[             {return TOKEN_LPAREN;}
\]             {return TOKEN_RPAREN;}
"=="              {return TOKEN_EQUALS;}
[ \t\n]        {}
.              {return TOKEN_ERROR;}



%%