#include <cstdio>

typedef long long int ll;

ll fact(ll n, ll mod) {
    ll ret = 1;
    while (n > 1) {
        ret = (ret * n) % mod;
        n--;
    }
    return ret;
}

ll pow(ll n, ll m, ll mod) {
    ll ret = 1;
    ll tmp = n;
    while (m > 0) {
        if (m % 2) ret = ret * tmp % mod;
        m /= 2;
        tmp = (tmp * tmp) % mod;
    }
    return ret;
}

ll ncr(ll n, ll r, ll mod) {
    ll a = fact(n, mod);
    ll b = fact(n - r, mod) * fact(r, mod) % mod;
    return a * pow(b, mod - 2, mod) % mod;
}

int main() {
    ll n, k, m, ans = 1;
    scanf("%lld %lld %lld", &n, &k, &m);

    // lucas' theorem
    while (k) {
        ll a = n % m;
        ll b = k % m;
        if (a < b) {
            printf("0");
            return 0;
        }
        ans *= ncr(a, b, m);
        ans %= m;
        n /= m;
        k /= m;
    }
    printf("%lld", ans);
}