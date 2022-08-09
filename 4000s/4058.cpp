#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

struct coord {
    int y, x;
    coord(int y, int x):
    y(y), x(x) {};
};

int n, m, r;
int mapp[626][626];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<coord> v;

bool vis[626][626];

inline bool inborder(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int cury, curx;
char curdir;

int mxval, mxy, mxx;
char mxdir;

void dfs(int y, int x, int cnt) {
    if(cnt > mxval) {
        mxval = cnt;
        mxy = cury;
        mxx = curx;
        mxdir = curdir;
    }
    if(mapp[y][x] != 1) cnt++;
    for(int i=0 ; i<4 ; i++) {
        int nxy = y+dy[i];
        int nxx = x+dx[i];
        if(inborder(nxy, nxx) && !vis[nxy][nxx]) {
            vis[nxy][nxx] = true;
            dfs(nxy, nxx, cnt);
            vis[nxy][nxx] = false;
        }
    }
}

void sol(int casecnt)
{
    scanf("%d", &r);
    for(int i=0 ; i<r ; i++) {
        int ry, rx;
        scanf("%d %d", &ry, &rx);
        v.push_back(coord(ry, rx));
        vis[ry][rx] = true;
        mapp[ry][rx] = 1;
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(mapp[i][j] == 1) continue;
            vis[i][j] = true;

            cury = i, curx = j+1, curdir='E';
            if(inborder(i, j+1)) dfs(i, j+1, 1);

            cury = i-1, curx = j, curdir='N';
            if(inborder(i-1, j)) dfs(i-1, j, 1);

            cury = i+1, curx = j, curdir='S';
            if(inborder(i+1, j)) dfs(i+1, j, 1);

            cury = i, curx = j-1, curdir='W';
            if(inborder(i, j-1)) dfs(i, j-1, 1);


            vis[i][j] = false;
        }
    }
}

int main()
{
    int casecnt = 0;
    while(1) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        casecnt++;
        sol(casecnt);
        printf("Case %d: %d %d %d %c\n", casecnt, mxval, mxy, mxx, mxdir);
    }
}