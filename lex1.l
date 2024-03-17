// 	lexer programm

%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%
[ \t]+          { printf("Whitespace\n"); }
\n              { printf("Newline\n"); }
"if"|"else"|"while"|"for"|"int"|"float"|"char"|"return" { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier: %s\n", yytext); }
.               { printf("Character: %s\n", yytext); }
%%

int main() {
    char input[] = "if (x > 5) {\n\tprintf(\"Hello World!\");\n}\nelse {\n\tprintf(\"Goodbye!\");\n}";
    yy_scan_string(input); // Provide input string to the lexer
    yylex(); // Tokenize the input string
    return 0;
}
