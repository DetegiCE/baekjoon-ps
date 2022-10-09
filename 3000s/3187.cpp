#include<bits/stdc++.h>
using namespace std;

int n, m;
char mapp[251][251];
bool vis[251][251];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int kcnt, vcnt;

inline bool inborder(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < m);
}

void dfs(int y, int x) {
    vis[y][x] = true;
    if(mapp[y][x] == 'k') kcnt++;
    if(mapp[y][x] == 'v') vcnt++;
    for(int i=0 ; i<4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inborder(ny, nx) && !vis[ny][nx] && mapp[ny][nx] != '#') {
            dfs(ny, nx);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", mapp[i]);
    }
    
    int totk = 0, totv = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if((mapp[i][j] == 'k' || mapp[i][j] == 'v') && !vis[i][j]) {
                kcnt = 0;
                vcnt = 0;
                dfs(i, j);
                if(kcnt > vcnt) totk += kcnt;
                else totv += vcnt;
            }
        }
    }
    printf("%d %d", totk, totv);
}