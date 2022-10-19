#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

#define MOD 1000000007

typedef long long ll;

int n, m;
ll mapp[1001][1001];

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++) mapp[1][i] = 1;
    for(int i=1 ; i<=n ; i++) mapp[i][1] = 1;
    for(int i=2 ; i<=n ; i++) {
        for(int j=2 ; j<=m ; j++) {
            mapp[i][j] = (mapp[i-1][j] + mapp[i][j-1] + mapp[i-1][j-1]) % MOD;
        }
    }
    
    cout << mapp[n][m];
}
