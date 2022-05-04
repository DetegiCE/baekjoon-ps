#include<cstdio>

bool aa(char a, char b){
    return (a == 'A' && b == 'A') || (a == 'A' && b == 'O') || (a == 'O' && b == 'A');
}

bool abab(char a, char b) {
    return (a == 'A' && b == 'B') || (a == 'B' && b == 'A'); 
}

bool bb(char a, char b) {
    return (a == 'B' && b == 'B') || (a == 'B' && b == 'O') || (a == 'O' && b == 'B');
}

bool oo(char a, char b) {
    return (a == 'O' && b == 'O');
}

int main()
{
    char a1, a2, b1, b2;
    scanf("%c%c %c%c",&a1,&a2,&b1,&b2);
    if(aa(a1, b1) || aa(a1, b2) || aa(a2, b1) || aa(a2, b2)) printf("A ");
    if(abab(a1, b1) || abab(a1, b2) || abab(a2, b1) || abab(a2, b2)) printf("AB ");
    if(bb(a1, b1) || bb(a1, b2) || bb(a2, b1) || bb(a2, b2)) printf("B ");
    if(oo(a1, b1) || oo(a1, b2) || oo(a2, b1) || oo(a2, b2)) printf("O ");
}