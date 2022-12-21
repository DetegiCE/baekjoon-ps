#include<bits/stdc++.h>
using namespace std;

int n, m;
int space[1002][1002], dp[3][1002][1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> space[i][j];
            if(!i) dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = space[i][j];
        }
    }
    for(int i=1 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(j > 0) dp[0][i][j] = min(dp[1][i-1][j], dp[2][i-1][j-1]) + space[i][j];
            else dp[0][i][j] = dp[1][i-1][j] + space[i][j];
            
            if(j > 0 && j < m-1) dp[1][i][j] = min(dp[0][i-1][j+1], dp[2][i-1][j-1]) + space[i][j];
            else if(j == m-1) dp[1][i][j] = dp[2][i-1][j-1] + space[i][j];
            else dp[1][i][j] = dp[0][i-1][j+1] + space[i][j];
            
            if(j < m-1) dp[2][i][j] = min(dp[1][i-1][j], dp[0][i-1][j+1]) + space[i][j];
            else dp[2][i][j] = dp[1][i-1][j] + space[i][j];
        }
    }
    
    int spmv = dp[0][n-1][0];
    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<3 ; j++)
            spmv = min(spmv, dp[j][n-1][i]);
    }
    cout << spmv;
}