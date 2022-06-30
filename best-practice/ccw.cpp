#include<cstdio>
#include<utility>
using namespace std;
#define _ABS(A) (A>0?A:-A)
#define FI first
#define SE second

typedef long long ll;

pair<ll, ll> p[10001];

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

ll ccw(int a, int b, int c) {
    return p[a].FI*p[b].SE + p[b].FI*p[c].SE + p[c].FI*p[a].SE - p[a].SE*p[b].FI - p[b].SE*p[c].FI - p[c].SE*p[a].FI;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }

    ll ans = 0;
    for(int i=1 ; i<n-1 ; i++) {
        ans += ccw(p[0].first, p[0].second, p[i].first, p[i].second, p[i+1].first, p[i+1].second);
    }
    printf("%.1f", _ABS(ans)/2.0);
}