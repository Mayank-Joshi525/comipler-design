#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
char prol[7][10]={"s","A","A","B","B","C","C"}; 
char pror[7][10]={"Aa","Bb","Cd","aB","@","Cc","@"}; 
char  prod[7][10]={"s-->A","A-->Bb","A-->Cd","B-->aB","B-->@","C-->Cc","C-->@"}; 
char first[7][10]={"abcd","ab",cd","a@","@","c@","@"}; 
char follow[7][10]={"$","$","$","a$","b$","c$","d$"}; 
 
Dept. of CSE 17  
char table[5][6][10]; 
{ 
switch(c) 
{ 
case 'S':return0; 
case 'A':return1; 
 
case 'B':return2; 
case 'C':return3; 
case 'a':return0; 
case 'b':return1; 
case 'c':return2; 
case 'd':return3; 
case '$':return4; 
} 
retun(2); 
} 
void main() 
{ 
int i,j,k; 
clrscr(); 
for(i=0;i<5;i++) 
for(j=0;j<6;j++) 
strcpy(table[i][j]," "); 
printf("\n The following is the predictive parsing table for the following grammar:\n"); 
for(i=0;i<7;i++) 
printf("%s\n",prod[i]); 
printf("\n Predictive parsing table is:\n "); 
fflush(stdin); 
for(i=0;i<7;i++) 
{ 
k=strlen(first[i]); 
for(j=0;j<10;j++) 
if(first[i][j]!='@') 
Dept. of CSE 18  
strcpy(table[numr(prol[i][0])+1][numr(first[i][j])+1],prod[i]); 
} 
for(i=0;i<7;i++) 
{ 
if(strlen(pror[i])==1) 
{ 
if(pror[i][0]=='@') 
{ 
k=strlen(follow[i]); 
 
 
for(j=0;j<k;j++) 
strcpy(table[numr(prol[i][0])+1][numr(follow[i][j])+1]prod[i]); 
} 
} 
} 
strcpy(table[0][0]," "); 
strcpy(table[0][1],"a"); 
strcpy(table[0][2],"b"); 
strcpy(table[0][3],"c"); 
strcpy(table[0][4],"d"); 
strcpy(table[0][5],"$"); 
strcpy(table[1][0],"S"); 
strcpy(table[2][0],"A"); 
strcpy(table[3][0],"B"); 
strcpy(table[4][0],"C"); 
printf("\n \n"); 
for(i-0;i<5;i++) 
for(j=0;j<6;j++) 
{ 
printf("%s_10S",table[i][j]); 
if(j==5) 
printf("\n \n"); 
} 
getch();
