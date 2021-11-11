#include<cstdio>

typedef long long int ll;

ll pow(ll b, ll u) {
    ll prod = 1;
    for(int i=0 ; i<u ; i++, prod *= b);
    return prod;
}

ll f(ll n) {
    ll cnt = n;
    ll div = 0;
    while (div < 51) {
        cnt += pow(2, div++) * (n / pow(2, div));
    }
    return cnt;
}

int main()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", f(b)-f(a-1));
}
