#include<cstdio>
#include<utility>
using namespace std;
#define _ABS(A) (A>0?A:-A)

typedef long long ll;

pair<ll, ll> p[10001];

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

int main()
{
    int n;
    for(int i=0 ; i<3 ; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }
    ll ans = ccw(p[0].first, p[0].second, p[1].first, p[1].second, p[2].first, p[2].second);
    printf("%lld", ans==0?0:ans/_ABS(ans));
}