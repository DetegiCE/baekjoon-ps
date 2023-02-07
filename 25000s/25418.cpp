#include<bits/stdc++.h>
using namespace std;

int dp[1000003];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int a, k;
    cin >> a >> k;
    for(int i=0 ; i<a ; i++) dp[i] = -1;
    for(int i=a+1 ; i<=k ; i++) {
        dp[i] = k+1;
        if(dp[i-1] != -1) dp[i] = dp[i-1] + 1;
        if(!(i&1) && dp[i/2] != -1) dp[i] = min(dp[i], dp[i/2]+1);
    }
    cout << dp[k];
}
