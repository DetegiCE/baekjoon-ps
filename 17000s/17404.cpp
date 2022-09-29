#include<bits/stdc++.h>
using namespace std;

int n;
int cost[1001][3];
int dp[3][1001][3];
    
int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<3 ; j++) {
            scanf("%d", &cost[i][j]);
            
            dp[0][i][j] = 100001;
            dp[1][i][j] = 100001;
            dp[2][i][j] = 100001;
        }
    }
    dp[0][0][0] = cost[0][0];
    dp[1][0][1] = cost[0][1];
    dp[2][0][2] = cost[0][2];
    
    for(int c=0 ; c<3 ; c++)
        for(int i=1 ; i<n ; i++) {
            dp[c][i][0] = cost[i][0] + min(dp[c][i-1][1], dp[c][i-1][2]);
            dp[c][i][1] = cost[i][1] + min(dp[c][i-1][0], dp[c][i-1][2]);
            dp[c][i][2] = cost[i][2] + min(dp[c][i-1][1], dp[c][i-1][0]);    
        }
    
    int amin = 2e9;
    amin = min(amin, min(dp[0][n-1][1], dp[0][n-1][2]));
    amin = min(amin, min(dp[1][n-1][0], dp[1][n-1][2]));
    amin = min(amin, min(dp[2][n-1][1], dp[2][n-1][0]));
    
    printf("%d", amin);
}