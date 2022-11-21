#include <bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

ll dp[66][12];

int main() {
    INP;
    
    for(int i=0 ; i<=9 ; i++) dp[1][i] = 1;
    dp[1][10] = 10;
    for(int i=2 ; i<=64 ; i++) {
        for(int j=0 ; j<=9 ; j++) {
            for(int k=0 ; k<=j ; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
        for(int j=0 ; j<=9 ; j++) dp[i][10] += dp[i][j];
    }
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << dp[n][10] << '\n';
    }
}