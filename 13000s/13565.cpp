#include <bits/stdc++.h>
using namespace std;

int n, m;
int mapp[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

inline bool inborder(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

void dfs(int y, int x) {
    mapp[y][x] = 2;
    for(int i=0 ; i<4 ; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(inborder(ny, nx) && mapp[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            scanf("%1d", &mapp[i][j]);
        }
    }
    for(int i=1 ; i<=m ; i++) {
        if(mapp[1][i] == 0) {
            dfs(1, i);
            for(int j=1 ; j<=m ; j++) {
                if(mapp[n][j] == 2) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}