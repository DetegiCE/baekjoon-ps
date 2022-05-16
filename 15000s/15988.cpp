#include<cstdio>
#define MOD 1000000009

typedef long long ll;

ll ar[1000002];

int main()
{
    ar[1] = 1;
    ar[2] = 2;
    ar[3] = 4;
    for(int i=4 ; i<=1000000 ; i++) {
        ar[i] = ar[i-1] + ar[i-2] + ar[i-3];
        ar[i] %= MOD;
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ar[n] % MOD);
    }
}