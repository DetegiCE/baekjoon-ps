#include<bits/stdc++.h>
using namespace std;

int n, m;
char game[51][51];
bool vis[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0,-1, 0, 1};

inline bool inborder(int y, int x) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

void dfs(int y, int x, char c, int pary, int parx) {
    vis[y][x] = true;
    for(int i=0 ; i<4 ; i++) {
        int nxy = y + dy[i];
        int nxx = x + dx[i];
        if(inborder(nxy, nxx) && game[nxy][nxx] == c && vis[nxy][nxx] && nxy != pary && nxx != parx) {
            puts("Yes");
            exit(0);
        }
        if(inborder(nxy, nxx) && game[nxy][nxx] == c && !vis[nxy][nxx]) {
            dfs(nxy, nxx, c, y, x);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", game[i]);
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            memset(vis, false, sizeof(vis));
            dfs(i, j, game[i][j], -1, -1);
        }
    }
    puts("No");
}