#include<cstdio>
#include<queue>
using namespace std;

int n, m;
char mapp[11][11];

struct board {
    int ry, rx, by, bx, cnt;

    board(int ry, int rx, int by, int bx, int cnt):
        ry(ry), rx(rx), by(by), bx(bx), cnt(cnt) {}
};

int rsx, rsy, bsx, bsy;
queue<board> q;
bool vis[11][11][11][11]; // ry rx by bx

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf("%s", mapp[i]);
        for(int j=0 ; j<m ; j++) {
            if(mapp[i][j] == 'R') rsy = i, rsx = j;
            if(mapp[i][j] == 'B') bsy = i, bsx = j;
        }
    }

    q.push(board(rsy, rsx, bsy, bsx, 0));
    vis[rsy][rsx][bsy][bsx] = 1;
    while(!q.empty()) {
        board qf = q.front(); q.pop();

        if(mapp[qf.ry][qf.rx] == 'O') {
            printf("%d", qf.cnt);
            return 0;
        }

        for(int i=0 ; i<4 ; i++) {
            int nry = qf.ry;
            int nrx = qf.rx;
            int nby = qf.by;
            int nbx = qf.bx;

            int rcnt = 0, bcnt = 0;

            while(mapp[nry+dy[i]][nrx+dx[i]] != '#' && mapp[nry][nrx] != 'O') {
                nry += dy[i];
                nrx += dx[i];
                rcnt++;
            }
            while(mapp[nby+dy[i]][nbx+dx[i]] != '#' && mapp[nby][nbx] != 'O') {
                nby += dy[i];
                nbx += dx[i];
                bcnt++;
            }

            if(mapp[nby][nbx] == 'O') continue;

            if(nry == nby && nrx == nbx) {
                if(rcnt > bcnt) {
                    nry -= dy[i];
                    nrx -= dx[i];
                }
                else {
                    nby -= dy[i];
                    nbx -= dx[i];
                }
            }

            if(vis[nry][nrx][nby][nbx]) continue;

            if(qf.cnt < 10) {
                vis[nry][nrx][nby][nbx] = 1;
                q.push(board(nry, nrx, nby, nbx, qf.cnt+1));
            }
        }
    }

    printf("-1");
    return 0;
}