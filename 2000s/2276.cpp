#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int m, n, ans;
int mapp[303][303];
bool vis[303][303];
priority_queue<pip> pq;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

inline bool inborder(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int val) {
    for(int i=0 ; i<4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inborder(ny, nx) && !vis[ny][nx]) {
            vis[ny][nx] = true;
            if(mapp[ny][nx] > val) pq.push(MP(-mapp[ny][nx], MP(ny, nx)));
            else {
                ans += val - mapp[ny][nx];
                dfs(ny, nx, val);
            }
        }
    }
}
 
int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> m >> n;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> mapp[i][j];
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                pq.push(MP(-mapp[i][j], MP(i, j)));
                vis[i][j] = true;
            }
        }
    }
    while(!pq.empty()) {
        pip cur = pq.top();
        pq.pop();
        dfs(cur.second.first, cur.second.second, -cur.first);
    }
    cout << ans;
}
