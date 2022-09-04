#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009

int s[100001][4];

int main()
{
    int t;
    s[1][1] = 1;
    s[2][2] = 1;
    s[3][1] = s[3][2] = s[3][3] = 1;
    s[4][1] = 2;
    s[4][3] = 1;
    for(int i=5 ; i<=100000 ; i++) {
        s[i][1] = s[i-1][2] + s[i-1][3];
        s[i][2] = s[i-2][1] + s[i-2][3];
        s[i][3] = s[i-3][1] + s[i-3][2];
        s[i][1] %= MOD;
        s[i][2] %= MOD;
        s[i][3] %= MOD;
    }
    scanf("%d", &t);
    while(t--) {
        int a;
        scanf("%d", &a);
        printf("%d\n", ((s[a][1]+s[a][2])%MOD+s[a][3])%MOD);
    }
}