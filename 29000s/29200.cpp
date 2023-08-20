#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a[200005], x[200005], dp[200005][5];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        x[i] = x[i-1] ^ a[i];
    }
    
    dp[1][1] = x[1];
    dp[2][2] = x[2];
    dp[3][1] = x[2] + a[3];
    dp[3][2] = a[1] + (x[3] ^ x[1]);
    dp[3][3] = x[3];
    
    if(n <= 2) {
        cout << x[n];
        return 0;
    }
    if(n == 3) {
        cout << max(dp[3][1], max(dp[3][2], dp[3][3]));
        return 0;
    }
    
    // for(int i=1 ; i<=n ; i++) cout << x[i] << ' '; cout << '\n';
    
    for(int i=4 ; i<=n ; i++) {
        for(int j=1 ; j<=4 ; j++) {
            for(int k=1 ; k<=4 ; k++) {
                if(j == k) continue;
                if(dp[i-j][k] == 0) continue;
                ll cur = dp[i-j][k] + (x[i] ^ x[i-j]);
                dp[i][j] = max(dp[i][j], cur);
                // cout << i << ' ' << j << ' ' << k << ' ' << cur << '\n';
            }   
        }
    }
    
    // for(int i=1 ; i<=n ; i++) {
    //     for(int j=1 ; j<=4 ; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    ll ans = 0;
    for(int i=1 ; i<=4 ; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}

/*
6
10 23 6 31 8 13


*/
