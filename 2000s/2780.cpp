#include<bits/stdc++.h>
using namespace std;

#define MOD 1234567

int dp[1001][10];

int getp(int pos, int *b) {
    int s = 0;
    for(int i=0 ; i<5 ; i++) {
        if(b[i] == -1) break;
        s += dp[pos-1][b[i]];
    }
    return s % MOD;
}

int a[10][5] = {{7, -1}, {2,4,-1}, {1, 3, 5,-1}, {2, 6,-1}, {1, 5, 7,-1}, {2, 4, 6, 8,-1},
                {3, 5, 9,-1}, {0, 4, 8,-1}, {5, 7, 9,-1}, {6, 8,-1}};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0 ; i<10 ; i++) dp[1][i] = 1;
    for(int i=2 ; i<=1000 ; i++) {
        for(int j=0 ; j<10 ; j++) {
            dp[i][j] = getp(i, a[j]);
        }
    }
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int s = 0;
        for(int i=0 ; i<10 ; i++) {
            s += dp[n][i];
        }
        cout << (s % MOD) << '\n';
    }
    
}
