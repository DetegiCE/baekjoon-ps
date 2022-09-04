#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll f[21][21];
ll mn;

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            scanf("%lld", &f[i][j]);
        }
    }
    mn = LONG_MAX;
    
    for(int i=1 ; i<(1<<n)-1 ; i++) {
        int t1[21] = {0};
        int t0[21] = {0};
        int t1cnt = 0;
        int t0cnt = 0;
        ll t1s = 0;
        ll t0s = 0;
        for(int j=0 ; j<n ; j++) {
            if(i & (1<<j)) { //team 1
                t1[t1cnt++] = j;
                if(t1cnt > 1) {
                    for(int k=0 ; k<t1cnt-1 ; k++) {
                        t1s += f[j][t1[k]];
                        t1s += f[t1[k]][j];
                    }
                }
            }
            else {
                t0[t0cnt++] = j;
                if(t0cnt > 1) {
                    for(int k=0 ; k<t0cnt-1 ; k++) {
                        t0s += f[j][t0[k]];
                        t0s += f[t0[k]][j];
                    }
                }
            }
        }
        // printf("%d %lld %lld\n", i, t0s, t1s);
        mn = min(mn, abs(t1s-t0s));
    }
    
    printf("%lld", mn);
}