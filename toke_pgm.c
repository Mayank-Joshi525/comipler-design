#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return true;
    return false;
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return true;
    return false;
}

bool isKeyword(char *str) {
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return true;
    return false;
}

bool validIdentifier(char *str) {
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return false;
    return true;
}

void parse(char *str, int *keywordCount, int *operatorCount, int *identifierCount, int *newlineCount) {
    int len = strlen(str);
    int i = 0;

    while (i < len) {
        // Skip whitespace
        while (i < len && str[i] == ' ') {
            i++;
        }

        if (isDelimiter(str[i]) == true) {
            // Check if it's an operator
            if (isOperator(str[i])) {
                (*operatorCount)++;
            }
            i++;
        } else {
            // It's not a delimiter, it's part of an identifier or keyword
            int start = i;
            while (i < len && !isDelimiter(str[i])) {
                i++;
            }
            int end = i - 1;
            char token[50]; // Assuming max token length is 50
            strncpy(token, str + start, end - start + 1);
            token[end - start + 1] = '\0';

            if (isKeyword(token)) {
                (*keywordCount)++;
            } else if (validIdentifier(token)) {
                (*identifierCount)++;
            }
        }

        // Check for newline
        if (i < len && str[i] == '\n') {
            (*newlineCount)++;
            i++;
        }
    }
}

int main() {
    char str[100] = "int a = b + mayank; while(i<6){break;   }\n";

    int keywordCount = 0, operatorCount = 0, identifierCount = 0, newlineCount = 0;
    parse(str, &keywordCount, &operatorCount, &identifierCount, &newlineCount);

    printf("Number of keywords: %d\n", keywordCount);
    printf("Number of operators: %d\n", operatorCount);
    printf("Number of identifiers: %d\n", identifierCount);
    printf("Number of newlines: %d\n", newlineCount);

    return 0;
}
