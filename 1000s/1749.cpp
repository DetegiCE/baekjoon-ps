#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll mat[202][202];
ll acc[202][202];
ll ans = -10001;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> mat[i][j];
            acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1] + mat[i][j];
            ans = max(ans, mat[i][j]);
        }
    }
    
    for(int dy=1 ; dy<=n ; dy++) {
        for(int dx=1 ; dx<=m ; dx++) {
            for(int sy=1 ; sy<=n-dy+1 ; sy++) {
                for(int sx=1 ; sx<=m-dx+1 ; sx++) {
                    int ey = sy+dy-1;
                    int ex = sx+dx-1;
                    ll csum = acc[ey][ex] - acc[ey][sx-1] - acc[sy-1][ex] + acc[sy-1][sx-1];
                    ans = max(ans, csum);
                }
            }
        }
    }
    
    cout << ans;
}
