// RE TO NFA
#include<stdio.h>
#include<string.h>

int main() {
    char reg[5];
    int q[4][3] = {0}; // Transition table
    int j = 1;

    scanf("%s", reg);
    printf("Given regular expression: %s\n", reg);

    // Constructing the transition table
    if (reg[0] == 'a') {
        q[0][0] = 1;
    }

    q[1][1] = 2;
    q[2][2] = 3;

    // Printing the transition table
    printf("\n\tNFA Transition Table for a*b\n");
    printf("_____________________\n");
    printf("Current State | Input | Next State\n");
    printf("_____________________\n");

    for (int i = 0; i < 4; i++) {
        if (q[i][0] != 0) printf("\n  q[%d]       |   a   |  q[%d]", i, q[i][0]);
        if (q[i][1] != 0) printf("\n  q[%d]       |   b   |  q[%d]", i, q[i][1]);
        if (q[i][2] != 0) printf("\n  q[%d]       |   ε   |  q[%d]", i, q[i][2]);
    }

    printf("\n_____________________\n");

    return 0;
}
//INPUT a*b
