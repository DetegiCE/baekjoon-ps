#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;

vector<pii> vp[6][6];
int mapp[6][6], r, c;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

inline bool inborder(int y, int x) {
    return (0 <= y && y < 5 && 0 <= x && x < 5);
}

void bfs(int y, int x) {
    bool vis[6][6];
    for(int i=0 ; i<5 ; i++) for(int j=0 ; j<5 ; j++) vis[i][j] = false;
    queue<pii> q;
    q.push(MP(y, x));
    int curv = mapp[y][x];
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        
        for(int i=0 ; i<4 ; i++) {
            int nfy = qfy + dy[i];
            int nfx = qfx + dx[i];
            if(inborder(nfy, nfx) && !vis[nfy][nfx] && mapp[nfy][nfx] != -1) {
                q.push(MP(nfy, nfx));
                vis[nfy][nfx] = true;
                if(mapp[nfy][nfx] == curv + 1) {
                    vp[y][x].push_back(MP(nfy, nfx));
                }
            }
        }
    }
}

int dfs(int y, int x, int v) {
    // cout << y << ' ' << x << ' ' << v << '\n';
    int mnv = 9999999;
    int curdst[6][6];
    for(int i=0 ; i<5 ; i++) for(int j=0 ; j<5 ; j++) curdst[i][j] = 999;
    curdst[y][x] = 0;
    queue<pii> q;
    q.push(MP(y, x));
    while(!q.empty()) {
        pii qf = q.front();
        q.pop();
        int qfy = qf.first;
        int qfx = qf.second;
        
        for(int i=0 ; i<4 ; i++) {
            int nfy = qfy + dy[i];
            int nfx = qfx + dx[i];
            if(inborder(nfy, nfx) && curdst[nfy][nfx] == 999 && mapp[nfy][nfx] != -1) {
                q.push(MP(nfy, nfx));
                curdst[nfy][nfx] = curdst[qfy][qfx] + 1;
            }
        }
    }
    
    if(v == 6) return 0;
    for(auto k: vp[y][x]) {
        int thisv = curdst[k.first][k.second] + dfs(k.first, k.second, v+1);
        mnv = min(mnv, thisv);
    }
    return mnv;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0 ; i<5 ; i++) {
        for(int j=0 ; j<5 ; j++) {
            cin >> mapp[i][j];
        }
    }
    cin >> r >> c;
    
    for(int i=0 ; i<5 ; i++) {
        for(int j=0 ; j<5 ; j++) {
            if(mapp[i][j] == -1) continue;
            if(mapp[i][j] == 6) continue;
            bfs(i, j);
        }
    }
    
    int ans = dfs(r, c, 0);
    if(ans >= 9999999) cout << -1;
    else cout << ans;
}