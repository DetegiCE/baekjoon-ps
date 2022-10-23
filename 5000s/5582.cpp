#include<bits/stdc++.h>
using namespace std;

string a, b;
int alen, blen;
int dp[4004][4004], mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a;
    cin >> b;
    alen = a.length();
    blen = b.length();
    
    dp[0][0] = (a[0]==b[0]?1:0);
    for(int i=1 ; i<alen ; i++)
        dp[i][0] = (b[0]==a[i]?1:0);
    for(int i=1 ; i<blen ; i++)
        dp[0][i] = (a[0]==b[i]?1:0);
    for(int i=1 ; i<alen ; i++) {
        for(int j=1 ; j<blen ; j++) {
            dp[i][j] = (a[i]==b[j]?dp[i-1][j-1]+1:0);
        }
    }
    for(int i=0 ; i<alen ; i++) {
        for(int j=0 ; j<blen ; j++) {
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx;
}