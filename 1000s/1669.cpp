#include <cmath>
#include <cstdio>

typedef long long int ll;

int main() {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if (x == y) {
        printf("0");
        return 0;
    }
    ll n = ((ll)sqrt(4 * (y - x)) - 2) / 2;
    ll sq = (ll)sqrt(y - x);
    printf("%lld",
           n * 2 + 1 + ((sq * sq) == (y - x) ? 0 : 1) +
               (((sq * sq) != (y - x) && (y - x - (sq * sq) > n + 1)) ? 1 : 0));
}