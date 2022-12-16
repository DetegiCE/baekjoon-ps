#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int a[52];

int main()
{
    int n;
    scanf("%d", &n);
    a[0] = a[1] = 1;
    for(int i=2 ; i<=n ; i++) {
        a[i] = (a[i-2] + a[i-1] + 1) % MOD;
    }
    printf("%d", a[n]);
}