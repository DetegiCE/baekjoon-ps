#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX(A,B) (A>B?A:B)

int n, c;
int mapp[3001][3001];
int fence[501][4];
int cow[501][2];
vector<int> tmpx, tmpy;

int curcnt;
int maxcnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};

void makeFence(int x1, int y1, int x2, int y2) {
    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);
    for(int i=x1*2 ; i<=x2*2 ; i++) 
        mapp[i][y1*2] = mapp[i][y2*2] = -1;
    for(int i=y1*2 ; i<=y2*2 ; i++) 
        mapp[x1*2][i] = mapp[x2*2][i] = -1;
}

void findCows(int x, int y) {
    // printf("fC(%d, %d)\n", x, y);
    if(mapp[x][y] == 1) curcnt++;
    mapp[x][y] = -2;
    for(int i=0 ; i<4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < tmpx.size()*2 && ny >= 0 && ny < tmpy.size()*2 && mapp[nx][ny] >= 0) {
            findCows(nx, ny);
        }
    }
}

int main()
{
    tmpx.push_back(-1);
    tmpy.push_back(-1);
    tmpx.push_back(1e7);
    tmpy.push_back(1e7);
    scanf("%d %d", &n, &c);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<4 ; j++) {
            scanf("%d", &fence[i][j]);
            if(j&1) tmpy.push_back(fence[i][j]);
            else tmpx.push_back(fence[i][j]);
        }
    }
    for(int i=0 ; i<c ; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
        tmpx.push_back(cow[i][0]);
        tmpy.push_back(cow[i][1]);
    }
    sort(tmpx.begin(), tmpx.end());
    sort(tmpy.begin(), tmpy.end());
    tmpx.erase(unique(tmpx.begin(), tmpx.end()), tmpx.end());
    tmpy.erase(unique(tmpy.begin(), tmpy.end()), tmpy.end());


    for(int i=0 ; i<n ; i++) {
        int nx1 = lower_bound(tmpx.begin(), tmpx.end(), fence[i][0]) - tmpx.begin();
        int nx2 = lower_bound(tmpx.begin(), tmpx.end(), fence[i][2]) - tmpx.begin();
        int ny1 = lower_bound(tmpy.begin(), tmpy.end(), fence[i][1]) - tmpy.begin();
        int ny2 = lower_bound(tmpy.begin(), tmpy.end(), fence[i][3]) - tmpy.begin();
        makeFence(nx1, ny1, nx2, ny2);
    }
    for(int i=0 ; i<c ; i++) {
        int nx = lower_bound(tmpx.begin(), tmpx.end(), cow[i][0]) - tmpx.begin();
        int ny = lower_bound(tmpy.begin(), tmpy.end(), cow[i][1]) - tmpy.begin();
        mapp[nx*2][ny*2] = 1;
    }


    // printf("   ");
    // for(int i=0 ; i<tmpy.size() ; i++) printf("%2d ", tmpy[i]); puts("");

    // for(int i=0 ; i<tmpx.size() ; i++) {
    //     printf("%2d ", tmpx[i]);
    //     for(int j=0 ; j<tmpy.size() ; j++) {
    //         printf("%2d ", mapp[i][j]);
    //     }
    //     puts("");
    // }

    for(int i=0 ; i<c ; i++) {
        int cx = lower_bound(tmpx.begin(), tmpx.end(), cow[i][0]) - tmpx.begin();
        int cy = lower_bound(tmpy.begin(), tmpy.end(), cow[i][1]) - tmpy.begin();
        if(mapp[cx*2][cy*2] == 1) {
            curcnt = 0;
            findCows(cx*2, cy*2);
            maxcnt = MAX(maxcnt, curcnt);
        }
    }
    printf("%d", maxcnt);
}
