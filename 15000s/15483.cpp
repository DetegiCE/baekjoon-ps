#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

string a, b;
int dp[1001][1001];
int ans = 0;

int main()
{
    INP;
    cin >> a;
    cin >> b;
    a = '_' + a;
    b = '_' + b;
    int asz = a.size(), bsz = b.size();
    
    for(int i=1 ; i<bsz ; i++) {
        dp[0][i] = i;
    }
    for(int i=1 ; i<asz ; i++) {
        dp[i][0] = i;
    }
    for(int i=1 ; i<asz ; i++) {
        for(int j=1 ; j<bsz ; j++) {
            dp[i][j] = (a[i] == b[j] ? dp[i-1][j-1] : min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1);
        }
    }
    
    cout << dp[asz-1][bsz-1];
}