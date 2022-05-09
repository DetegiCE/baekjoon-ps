#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> a;
    cin >> b;

    for(int i=0 ; i<a.length() ; i++) 
        dp[i][0] = (a[i] == b[0] || dp[i-1][0] ? 1 : 0);
    for(int i=0 ; i<b.length() ; i++) 
        dp[0][i] = (a[0] == b[i] || dp[0][i-1] ? 1 : 0);

    for(int i=1 ; i<a.length() ; i++)
        for(int j=1 ; j<b.length() ; j++)
            dp[i][j] = (a[i] == b[j] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]));

    cout << dp[a.length()-1][b.length()-1];
}