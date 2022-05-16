#include<cstdio>

int n, m, ar[103][103];
int cnt[3] = {0, 1};

void dfs(int x, int y, int targ, int fil) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = { 0,-1, 0, 1};
    for(int i=0 ; i<4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m && ar[nx][ny] == targ) {
            ar[nx][ny] = fil;
            dfs(nx, ny, targ, fil);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(ar[i][j] == 0) dfs(i, j, 0, --cnt[0]);
            if(ar[i][j] == 1) dfs(i, j, 1, ++cnt[1]);
        }
    }
    printf("%d %d\n", -cnt[0], cnt[1]-1);
}