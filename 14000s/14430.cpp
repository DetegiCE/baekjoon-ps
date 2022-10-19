#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

int n, m, ans;
int mapp[301][301];

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> mapp[i][j];
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            mapp[i][j] = max(mapp[i-1][j], mapp[i][j-1]) + mapp[i][j];
            ans = max(ans, mapp[i][j]);
        }
    }
    
    cout << ans;
}
