#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<ll,ll> pii;
#define MOD 1000000007

ll n, k;
char mapp[3003][3003];
ll e[3003][3003];
ll m[3003][3003];

int main()
{
    scanf("%lld %lld", &n, &k);
    for(int i=1 ; i<=n ; i++) scanf(" %s", &mapp[i][1]);
    if(mapp[1][1] == 'E') e[1][1] = 1;
    if(mapp[1][1] == 'M') m[1][1] = 1;
    for(int i=2 ; i<=n ; i++) {
        e[i][1] = e[i-1][1] + (mapp[i][1]=='E'?1:0);
        m[i][1] = m[i-1][1] + (mapp[i][1]=='M'?1:0);
    }
    for(int i=2 ; i<=k ; i++) {
        e[1][i] = e[1][i-1] + (mapp[1][i]=='E'?1:0);
        m[1][i] = m[1][i-1] + (mapp[1][i]=='M'?1:0);
    }
    for(int i=2 ; i<=n ; i++) {
        for(int j=2 ; j<=k ; j++) {
            e[i][j] = (e[i-1][j] + e[i][j-1] - e[i-1][j-1] + (mapp[i][j]=='E'?1:0) + MOD) % MOD;
            m[i][j] = (m[i-1][j] + m[i][j-1] - m[i-1][j-1] + (mapp[i][j]=='M'?1:0) + MOD) % MOD;
        }
    }
    
    ll ans = 0;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=k ; j++) {
            if(mapp[i][j] == 'S') {
                ll ecnt = e[i][j];
                ll mcnt = m[n][k] - m[i-1][k] - m[n][j-1] + m[i-1][j-1];
                ll tot = (ecnt * mcnt) % MOD;
                ans += tot;
                ans %= MOD;
            }
        }
    }
    printf("%lld", ans);
}