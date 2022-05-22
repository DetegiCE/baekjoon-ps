#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MIN(A,B) (A>B?B:A)
#define MAX(A,B) (A>B?A:B)

struct COORD {
    int y, x;
};

int n;
char mapp[51][51];
int piro[51][51];
bool vis[51][51];
int mapmin=1, mapmax=1, kcnt, maxh, ans;
queue<COORD> q;
COORD ppoint;

int dx[8] = {-1, 0, 1, 1, 1, 0,-1,-1};
int dy[8] = {-1,-1,-1, 0, 1, 1, 1, 0};

int main()
{
    scanf("%d", &n);
    ans = 2147483647;
    for(int i=1 ; i<=n ; i++) {
        scanf("%s", &mapp[i][1]);
        for(int j=1 ; j<=n ; j++) {
            if(mapp[i][j] == 'P') {
                ppoint.y = i, ppoint.x = j;
            }
            if(mapp[i][j] == 'K') kcnt++;
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            scanf("%d", &piro[i][j]);
            maxh = MAX(maxh, piro[i][j]);
            if(mapp[i][j] != '.') mapmax = MAX(mapmax, piro[i][j]);
        }
    }

    int curcnt = 0;
    while(mapmin <= mapmax && mapmax <= maxh) {
        //printf("%d %d %d\n", mapmin, mapmax, ans);
        q.push(ppoint);
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                vis[i][j] = false;
            }
        }
        vis[ppoint.y][ppoint.x] = true; 
        curcnt = 0;
        while(!q.empty()) {
            COORD qf = q.front(); q.pop();
            int qfy = qf.y, qfx = qf.x;
            if(mapp[qfy][qfx] == 'K') curcnt++;
            if(curcnt == kcnt) break;
            for(int i=0 ; i<8 ; i++) {
                int ny = qfy + dy[i];
                int nx = qfx + dx[i];
                if(ny > 0 && ny <= n && nx > 0 && nx <= n && !vis[ny][nx] && piro[ny][nx] >= mapmin && piro[ny][nx] <= mapmax) {
                    COORD nc = {ny, nx};
                    vis[ny][nx] = true;
                    q.push(nc);
                }
            }
        }
        while(!q.empty()) q.pop();
        if(curcnt == kcnt) {
            ans = MIN(ans, mapmax-mapmin);
            mapmin++;
        }
        else mapmax++;
    }
    printf("%d", ans);
}