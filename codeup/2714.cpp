#include<cstdio>
#include<queue>
using namespace std;

typedef struct hive {
    int x, y, r;
} HIVE;

int n, q;
int mapp[502][502];
bool vis[502][502];

queue<HIVE> qq, qe;

int dx[6] = {-1,-1, 0, 1, 1, 0};
int dy[6] = {-1, 0, 1, 1, 0,-1};

int main()
{
    scanf("%d %d", &n, &q);
    while(q--) {
        int x, y, r, k;
        scanf("%d %d %d %d", &x, &y, &r, &k);
        HIVE st = {x, y, 0};
        qq.push(st);
        qe.push(st);
        while(true) {
            HIVE qf = qq.front();
            qq.pop();
            if(qf.r == r) break;
            for(int i=0 ; i<6 ; i++) {
                int nx = qf.x + dx[i];
                int ny = qf.y + dy[i];
                if(nx > 0 && nx <= n && ny > 0 && ny <= n && !vis[nx][ny]) {
                    HIVE nst = {nx, ny, qf.r+1};
                    qq.push(nst);
                    qe.push(nst);
                    vis[nx][ny] = true;
                }
            }
        }
        while(!qe.empty()) {
            HIVE qf = qe.front();
            qe.pop();
            //printf("%d %d %d\n", qf.x, qf.y, k);
            mapp[qf.x][qf.y] += k;
            vis[qf.x][qf.y] = false;
        }
        while(!qq.empty()) qq.pop();
    }
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    printf("%d", mapp[xx][yy]);
}