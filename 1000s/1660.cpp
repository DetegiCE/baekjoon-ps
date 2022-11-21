#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
typedef long long ll;

int n, dp[300003];
int daepo[124];

int main()
{
    INP;
    
    cin >> n;
    
    int j=1;
    while(j*(j+1)*(j+2)/6 <= n) {
        daepo[j] = j*(j+1)*(j+2)/6;
        j++;
    }
    
    for(int i=1 ; i<=n ; i++) dp[i] = i;
    for(int i=2 ; i<j ; i++) {
        for(int k=daepo[i] ; k<=n ; k++) {
            for(int m=1 ; m<=i ; m++) {
                dp[k] = min(dp[k], dp[k-daepo[i]] + 1);
            }
        }
    }
    
    cout << dp[n];
}