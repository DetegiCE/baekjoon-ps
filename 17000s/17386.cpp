#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
#define _ABS(A) (A>0?A:-A)
#define FI first
#define SE second

typedef long long ll;
typedef pair<ll, ll> pll;

pll p[4];

ll ccw(int a, int b, int c) {
    ll t = p[a].FI*p[b].SE + p[b].FI*p[c].SE + p[c].FI*p[a].SE - p[a].SE*p[b].FI - p[b].SE*p[c].FI - p[c].SE*p[a].FI;
    if(t > 0) return 1;
    else if(t == 0) return 0;
    else return -1;
}

bool check(int a, int b, int c, int d) {
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);

    if(abc*abd == 0LL && cda*cdb==0LL) {
        if(p[a] > p[b]) swap(p[a], p[b]);
        if(p[c] > p[d]) swap(p[c], p[d]);
        return p[a] <= p[d] && p[c] <= p[b];
    }
    return abc*abd<=0LL && cda*cdb<=0LL;
}

int main()
{
    int n;
    for(int i=0 ; i<4 ; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }
    if(check(0, 1, 2, 3)) puts("1");
    else puts("0");
}