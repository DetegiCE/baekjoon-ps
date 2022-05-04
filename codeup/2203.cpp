#include<cstdio>
#include<cmath>

typedef long long ll;

bool isprime(ll n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(ll i=3 ; i*i<=n ; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    for(ll i = (ll)sqrt(n) ; i>=2 ; i--) {
        if(n % i == 0 && isprime(n/i)) {
            printf("%lld", n/i);
            return 0;
        }
        if(n % i == 0 && isprime(i)) {
            printf("%lld", i);
            return 0;
        }
    }
    printf("%lld", n);
}