#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
#define _ABS(A) (A>0?A:-A)
#define FI first
#define SE second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

pll p[4];

ll ccw(int a, int b, int c) {
    ll t = p[a].FI*p[b].SE + p[b].FI*p[c].SE + p[c].FI*p[a].SE - p[a].SE*p[b].FI - p[b].SE*p[c].FI - p[c].SE*p[a].FI;
    if(t > 0) return 1;
    else if(t == 0) return 0;
    else return -1;
}

pdd getIntersection(pll a, pll b, pll c, pll d) {
    double a1, b1, c1;
    double a2, b2, c2;

    if(a.FI == b.FI) {
        c1 = (double)a.FI;
    }
    else {
        a1 = (double)(b.SE-a.SE)/(b.FI-a.FI);
        b1 = a.SE - a1 * a.FI;
    }

    if(c.FI == d.FI) {
        c2 = (double)c.FI;
    }
    else {
        a2 = (double)(d.SE-c.SE)/(d.FI-c.FI);
        b2 = c.SE - a2 * c.FI;
    }

    pdd res;
    if(a.FI == b.FI && c.FI == d.FI) return make_pair(-1, -1);
    if(a.FI == b.FI) return make_pair(c1, a2*c1+b2);
    else if(c.FI == d.FI) return make_pair(c2, a1*c2+b1);
    else {
        res.FI = -(b1-b2)/(a1-a2);
        res.SE = a1*(res.FI) + b1;
        return res;
    }
    
}


void check(int a, int b, int c, int d) {
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);

    if(abc*abd <= 0LL && cda*cdb<=0LL) {
        if(p[a] > p[b]) swap(p[a], p[b]);
        if(p[c] > p[d]) swap(p[c], p[d]);
        if(abc*abd == 0LL && cda*cdb == 0LL) {
            if(p[a] > p[d] || p[c] > p[b]) {
                puts("0");
                return;
            }
        }
        puts("1");
        if(p[b] == p[c]) {
            printf("%lld %lld", p[b].FI, p[b].SE);
            return;
        }
        if(p[a] == p[d]) {
            printf("%lld %lld", p[a].FI, p[a].SE);
            return;
        }
        pdd inter = getIntersection(p[a], p[b], p[c], p[d]);
        printf("%.9lf %.9lf", inter.FI, inter.SE);
    }
    else {
        puts("0");
    }
}

int main()
{
    int n;
    for(int i=0 ; i<4 ; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }
    check(0, 1, 2, 3);
}