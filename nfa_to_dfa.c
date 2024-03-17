#include <stdio.h>

int main() {
    int nfa[4][2] = {{0}}; // Initialize NFA with zeros
    nfa[1][0] = 2;
    nfa[1][1] = 13;
    nfa[2][0] = 2;
    nfa[2][1] = 1;
    nfa[3][0] = 2;
    nfa[3][1] = 3;

    int dfa[10][2] = {{0}}; // Initialize DFA with zeros
    int dstate[10] = {0}; // Initialize dstate with zeros
    int n = 1, j, k, flag = 0, m, q, r; // Start with 1 state
    dstate[1] = 1;

    for (k = 1; dstate[k] != 0; k++) {
        m = dstate[k];
        if (m > 10) {
            q = m / 10;
            r = m % 10;
        } else {
            q = 0;
            r = m;
        }
        for (j = 0; j < 2; j++) {
            dfa[k][j] = nfa[r][j];
            flag = 0;
            for (int i = 1; i <= n; i++) {
                if (dfa[k][j] == dstate[i]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && dfa[k][j] != 0) {
                int nextState = dfa[k][j];
                int duplicate = 0;
                for (int l = 1; l <= n; l++) {
                    if (dstate[l] == nextState) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    dstate[++n] = nextState;
                }
            }
        }
    }

    // Print DFA Transition Table
    printf("State   |   a   |   b\n");
    printf("-----------------------\n");
    for (int i = 1; i < k; i++) {
        if (dstate[i] == 13) { // Print 13 instead of 3
            printf("  %d     |   %d   |   %d\n", 13, dfa[i][0], dfa[i][1]);
        } 
        else { // Exclude the last empty row
            printf("  %d     |   %d   |   %d\n", dstate[i], dfa[i][0], dfa[i][1]);
        }
    }

    return 0;
}
