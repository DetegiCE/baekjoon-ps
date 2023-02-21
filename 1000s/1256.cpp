#include<bits/stdc++.h>
using namespace std;
#define INF (1e9+1)
typedef long long ll;

ll n, m, k, comb[202][202];
char ans[202];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(ll i=0 ; i<=n+m ; i++) {
        for(ll j=0 ; j<=i ; j++) {
            if(j == 0 || i == j) comb[i][j] = 1;
            else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            if(comb[i][j] >= INF) comb[i][j] = INF;
        }
    }
    if(comb[n+m][m] < k) {
        cout << -1;
        return 0;
    }
    
    ll s = n + m;
    for(ll i=0 ; i<s ; i++) {
        ll cur = comb[n+m-1][n-1];
        if(n > 0 && k <= cur) {
            cout << 'a';
            n--;
        }
        else {
            cout << 'z';
            m--;
            k -= cur;
        }
    }
}
