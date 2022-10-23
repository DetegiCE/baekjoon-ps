#include<bits/stdc++.h>
using namespace std;

int n, coin[21], dp[21][10001], m;

void sol() {
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> coin[i];
    cin >> m;
    for(int i=0 ; i<=m ; i++) {
        dp[0][i] = (i % coin[0] == 0?1:0);
    }
    for(int i=1 ; i<n ; i++) {
        for(int j=0 ; j<=m ; j++) {
            if(j < coin[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
            }
        }
    }
    cout << dp[n-1][m] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}