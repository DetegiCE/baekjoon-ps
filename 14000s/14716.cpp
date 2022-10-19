#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, m;
int mapp[252][252];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, -1, -1, 0, 1, 1};

inline bool inborder(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

void dfs(int y, int x) {
    mapp[y][x] = 2;
    for(int i=0 ; i<8 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inborder(ny, nx) && mapp[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main()
{
    INP;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> mapp[i][j];
        }
    }
    
    int cnt = 0;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(mapp[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    
    cout << cnt;
}