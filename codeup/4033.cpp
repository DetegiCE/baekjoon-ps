#include<cstdio>

int main()
{
    int n, k, sum = 0, t;
    long long int ans = 1;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0 ; i<k ; i++) {
        scanf("%d", &t);
        sum += t;
    }
    n -= sum;
    n -= (k-1);
    for(long long int i=2 ; i<=n+k ; i++) ans *= i;
    for(long long int i=2 ; i<=n ; i++) ans /= i;
    for(long long int i=2 ; i<=k ; i++) ans /= i;
    printf("%lld", ans);
}