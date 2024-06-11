#include <iostream> 
#include <cstring> 
#include <stack> 
using namespace std; 
void push(stack<char>&st, char c) { 
st.push(c); 
} 
char pop(stack<char>&st) { 
    if (!st.empty()) { 
        char c = st.top(); 
st.pop(); 
        return c; 
    } 
    return 'x'; 
} 
void printstat(stack<char>&st) { 
    cout << "\n\t\t\t $"; 
    while (!st.empty()) { 
cout<<st.top(); 
st.pop(); 
    } 
    while (!st.empty()) { 
        push(st, st.top()); 
    }} 
int main() { 
    stack<char>st; 
    int i, j, k, l; 
    char s1[20], s2[20], ch1, ch2, ch3; 
cout << "\n\n\t\t LR PARSING"; 
    cout << "\n\t\t ENTER THE EXPRESSION"; 
    cin >> s1; 
 l = strlen(s1); 
    j = 0; 
    cout << "\n\t\t $"; 
    for (i = 0; i< l; i++) { 
        if (s1[i] == 'i' && s1[i + 1] == 'd') { 
            s1[i] = ' '; 
            s1[i + 1] = 'E'; 
printstat(st); 
            cout << "id"; 
            push(st, 'E'); 
printstat(st); 
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == 'd') { 
            push(st, s1[i]); 
printstat(st); 
}} 
printstat(st); 
 

 
    l = strlen(s2); 
    while (l){ 
        ch1 = pop(st); 
        if (ch1 == 'x') { 
            cout << "\n\t\t\t $"; 
            break; 
        } 
        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-') { 
            ch3 = pop(st); 
            if (ch3 != 'E') { 
                cout << "error"; 
                return 1; 
            } else { 
                push(st, 'E'); 
printstat(st); 
            } 
        } 
        ch2 = ch1; 
    } 
return 0; 
} 
