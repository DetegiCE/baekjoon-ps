#include<cstdio>
using namespace std;

typedef long long ll;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        ll x1, y1, x2, y2, n, cnt = 0;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        scanf("%lld", &n);
        for(int i=0 ; i<n ; i++) {
            ll x, y, r;
            scanf("%lld %lld %lld", &x, &y, &r);
            
            ll st = dist(x1, y1, x, y);
            ll en = dist(x2, y2, x, y);
            if(st < r*r && en > r*r) cnt++;
            if(st > r*r && en < r*r) cnt++;
        }
        printf("%lld\n", cnt);
    }
}