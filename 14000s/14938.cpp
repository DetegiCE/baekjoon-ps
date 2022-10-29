#include<bits/stdc++.h>
using namespace std;
#define INF 98765
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, m, r;
int item[101];
int mapp[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    for(int i=1 ; i<=n ; i++) {
        cin >> item[i];
        for(int j=1 ; j<=n ; j++) {
            mapp[i][j] = INF;
        }
        mapp[i][i] = 0;
    }
    for(int i=0 ; i<r ; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        mapp[a][b] = min(mapp[a][b], l);
        mapp[b][a] = min(mapp[b][a], l);
    }
    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(i == j) mapp[i][j] = 0;
                if(mapp[i][j] > mapp[i][k] + mapp[k][j]) {
                    mapp[i][j] = mapp[i][k] + mapp[k][j];
                }
            }
        }
    }
    
    int mx = 0;
    for(int i=1 ; i<=n ; i++) {
        int tsum = 0;
        for(int j=1 ; j<=n ; j++) {
            if(mapp[i][j] <= m) tsum += item[j];
        }
        mx = max(mx, tsum);
    }
    cout << mx;
}