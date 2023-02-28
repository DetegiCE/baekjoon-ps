#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int dp1[2503][2503];
int dp[2503];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    v.push_back(0);
    for(int i=1 ; i<=n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    if(n == 2) {
        if(v[1] == v[2]) cout << 1;
        else cout << 2;
        return 0;
    }
    
    for(int i=1 ; i<=n ; i++) {
        vector<int> nv;
        for(int j=0 ; j<i ; j++) nv.push_back(0);
        for(int j=i ; j<=n ; j++) nv.push_back(v[j]);
        bool hasn0 = false;
        for(int j=i+1 ; j<=n ; j++) {
            int amnv = min(nv[j-1], nv[j]);
            nv[j-1] -= amnv;
            nv[j] -= amnv;
            if(nv[j-1] != 0) hasn0 = true;
            // cout << i << ' ' << j << ' ' << amnv << ' ' << hasn0 << ' ';
            // cout << nv[j-1] << ' ' << nv[j] << '\n';
            if(!hasn0 && nv[j] == 0) dp1[i][j] = 1;
        }
    }
    
    // for(int i=1 ; i<=n ; i++) {
    //     for(int j=1 ; j<=n ; j++) {
    //         cout << dp1[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    dp[1] = 1;
    for(int i=2 ; i<=n ; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j=1 ; j<i ; j++) {
            if(dp1[j][i]) dp[i] = min(dp[i], dp[j-1]+i-j);
        }
    }
    
    cout << dp[n];
}
