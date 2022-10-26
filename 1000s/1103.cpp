#include<bits/stdc++.h>
using namespace std;

int n, m;
char smapp[55][55];
int mapp[55][55];
bool vis[55][55];
int dp[55][55];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool inb(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

int dfs(int y, int x) {
    if(!inb(y, x)) return 0;
    if(mapp[y][x] == -1) return 0;
    if(vis[y][x]) {
        cout << "-1";
        exit(0);
    }
    if(dp[y][x]) return dp[y][x];
    vis[y][x] = true;
    for(int i=0 ; i<4 ; i++) {
        int ny = y + dy[i] * mapp[y][x];
        int nx = x + dx[i] * mapp[y][x];
        dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
    }
    vis[y][x] = false;
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> smapp[i][j];
            if(smapp[i][j] == 'H') mapp[i][j] = -1;
            else mapp[i][j] = smapp[i][j] - '0';
            vis[i][j] = 0;
        }
    }
    
    cout << dfs(1, 1);
}