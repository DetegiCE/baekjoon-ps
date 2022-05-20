#include<cstdio>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    // (b-c) * x + b >= a
    printf("%d", (a-b-1)/(b-c)+2);
}

// 10 3 1 -> 5
// 700 45 32 -> 52
// 65869856 346375 45654 -> 219
