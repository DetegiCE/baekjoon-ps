#include<cstdio>
typedef long long ll;

int n, m, k;
bool sieve[4000004];
int cntprime[4000004];

int main()
{
    scanf("%d %d %d", &n, &k, &m);

    for(int i=2 ; i*i<=n ; i++) {
        if(!sieve[i]) {
            for(int j=i*2 ; j<=n ; j+=i) sieve[j] = true;
        }
    }

    for(int i=2 ; i<=n ; i++) {
        if(!sieve[i]) {
            for(ll factor = i ; factor <= n ; factor *= i) {
                cntprime[i] += (n/factor) - (k/factor) - ((n-k)/factor);
            }
        }
    }

    ll ans = 1;
    for(int i=2 ; i<=n ; i++) {
        for(int j=0 ; j<cntprime[i] ; j++) {
            ans *= i;
            ans %= m;
        }
    }
    printf("%lld", ans % m);
}