#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct coord {
    int y, x, eaten;
    coord(int y, int x, int eaten): y(y), x(x), eaten(eaten) {}
};

int n, mapp[21][21];

vector<coord> fish[7];
vector<coord> fishes;

coord curpos = coord(0, 0, 0);

int cursize = 2;
int cureat = 0;

int times = 0;

inline bool isin(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

int calcdist(int sty, int stx, int eny, int enx) {
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = { 0,-1, 0, 1};
    bool vis[21][21] = {false};
    queue<coord> q;
    q.push(coord(sty, stx, 0));
    vis[sty][stx] = true;
    while(!q.empty()) {
        coord qf = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++) {
            int nxty = qf.y + dy[i];
            int nxtx = qf.x + dx[i];
            if(nxty == eny && nxtx == enx) {
                return qf.eaten + 1;
            }
            if(isin(nxty, nxtx) && !vis[nxty][nxtx] && mapp[nxty][nxtx] <= cursize) {
                q.push(coord(nxty, nxtx, qf.eaten+1));
                vis[nxty][nxtx] = true;
            }
        }
    }
    return 402;
}

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            scanf("%d", &mapp[i][j]);
            if(1 <= mapp[i][j] && mapp[i][j] <= 6) {
                fish[mapp[i][j]].push_back(coord(i, j, 0));
            }
            if(mapp[i][j] == 9) {
                curpos = coord(i, j, 0);
                mapp[i][j] = 0;
            }
        }
    }   
    for(int i=0 ; i<fish[1].size() ; i++) {
        fishes.push_back(fish[1][i]);
    }

    int mxfar = 401;
    coord mxcoord = coord(0,0,0);
    int mxidx = -1;
    while(1) {
        mxfar = 401;
        mxcoord = coord(0,0,0);
        // printf("size: %d, eat: %d\n", cursize, cureat);
        for(int i=0 ; i<fishes.size() ; i++) {
            if(fishes[i].eaten == 0) {
                int dst = calcdist(curpos.y, curpos.x, fishes[i].y, fishes[i].x);
                if(dst < mxfar) {
                    mxfar = dst;
                    mxcoord = fishes[i];
                    mxidx = i;
                }
                else if(dst == mxfar) {
                    if(mxcoord.y == fishes[i].y) {
                        if(mxcoord.x > fishes[i].x) {
                            mxcoord.x = fishes[i].x;
                            mxidx = i;
                        }
                    }
                    else if(mxcoord.y > fishes[i].y) {
                        mxcoord = fishes[i];
                        mxidx = i;
                    }
                }
            }
        }
        // printf("mxfar: %d\ntimes: %d\n", mxfar, times);
        // printf("mxcoord: %d %d\n", mxcoord.y, mxcoord.x);
        // puts("============");
        if(mxfar == 401) {
            break;
        }
        else {
            times += mxfar;
            curpos = mxcoord;
            cureat ++;
            fishes[mxidx].eaten = 1;
            mapp[mxcoord.y][mxcoord.x] = 0;
        }
        if(cureat == cursize && cursize <= 6) {
            cureat = 0;
            for(int i=0 ; i<fish[cursize].size() ; i++) {
                fishes.push_back(fish[cursize][i]);
            }
            cursize++;
        }
    }
    printf("%d",times);
}