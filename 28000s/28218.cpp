#include<bits/stdc++.h>
using namespace std;

int n, m, k;
string mp[303];
int dp[303][303];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        cin >> mp[i];
    }
    dp[n-1][m-1] = -1;
    for(int i=n-1 ; i>=0 ; i--) {
        for(int j=m-1 ; j>=0 ; j--) {
            if(i==n-1 && j==m-1) continue;
            
            int flg = -1;
            if(i < n && mp[i+1][j] == '.' && dp[i+1][j] == -1) flg = 1;
            if(j < m && mp[i][j+1] == '.' && dp[i][j+1] == -1) flg = 1;
            for(int l=1 ; l<=k ; l++) {
                if(i+l < n && j+l < m && mp[i+l][j+l] == '.' && dp[i+l][j+l] == -1) flg = 1;
            }
            dp[i][j] = flg;
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        if(dp[a-1][b-1] == -1) cout << "Second\n";
        else cout << "First\n";
    }
}
