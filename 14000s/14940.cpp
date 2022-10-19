#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, m;
int mapp[1002][1002];
int sty, stx;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

typedef pair<int,int> pii;
queue<pii> q;

inline bool inborder(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> mapp[i][j];
            if(mapp[i][j] == 1) mapp[i][j] = -1;
            if(mapp[i][j] == 0) mapp[i][j] = -2;
            if(mapp[i][j] == 2) {
                mapp[i][j] = 0;
                sty = i;
                stx = j;
            }
        }
    }
    q.push(make_pair(sty, stx));
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        
        for(int i=0 ; i<4 ; i++) {
            int ny = qf.first + dy[i];
            int nx = qf.second + dx[i];
            if(inborder(ny, nx) && mapp[ny][nx] == -1) {
                mapp[ny][nx] = mapp[qf.first][qf.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(mapp[i][j] == -2) cout << "0 ";
            else cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
    
}