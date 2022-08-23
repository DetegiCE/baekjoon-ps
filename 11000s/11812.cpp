#include<bits/stdc++.h>
using namespace std;

#define NMX 10000

typedef long long ll;
ll n, k, q;
ll starts[NMX];
ll lev;

int main()
{
    scanf("%lld %lld %lld", &n, &k, &q);
    if(k == 1) {
        while(q--) {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", abs(a-b));
        }
        return 0;
    }
    starts[0] = 1;
    starts[1] = 2;
    for(int i=3 ; starts[i-2] + pow(k, i-2) <=n*k ; i++) {
        starts[i-1] = starts[i-2] + pow(k, i-2);
        lev = i-1;
    }
    while(q--) {
        ll x, y;
        ll xpos[NMX]={0}, ypos[NMX]={0};
        scanf("%lld %lld", &x, &y);

        ll xlev, ylev;
        for(xlev = 0 ;; xlev++) {
            if(starts[xlev] <= x && x < starts[xlev+1]) {
                break;
            }
        }
        for(ylev = 0 ;; ylev++) {
            if(starts[ylev] <= y && y < starts[ylev+1]) {
                break;
            }
        }
        // printf("%lld %lld\n", xlev, ylev);
        if(xlev == 0) {
            printf("%lld\n", ylev);
            continue;
        }
        else if(ylev == 0) {
            printf("%lld\n", xlev);
            continue;
        }

        xpos[xlev] = (x - starts[xlev]) % k;
        ypos[ylev] = (y - starts[ylev]) % k;
        x = (x - starts[xlev]) / k;
        y = (y - starts[ylev]) / k;
        for(int i=xlev-1 ; i>=0 ; i--) {
            xpos[i] = x % k;
            x /= k;
        }
        for(int i=ylev-1 ; i>=0 ; i--) {
            ypos[i] = y % k;
            y /= k;
        }

        ll scnt = 0;
        for(int i=0 ; i<=min(xlev, ylev)-1 ; i++) {
            if(xpos[i] == ypos[i]) scnt++;
            else break;
        }
        printf("%lld\n", xlev + ylev + 2 - scnt * 2);
    }
}