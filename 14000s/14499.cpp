#include<cstdio>

int mapp[21][21];
int dice[7];
int top, bottom;
int ee, ww, nn, ss;
int n, m, x, y;

/*
  2
4 1 3
  5
  6
*/

inline int isin(int x, int y) {
    return 0 <= x && x <= n-1 && 0 <= y && y <= m-1;
}

void east() {
    int t = top;
    top = ww;
    ww = bottom;
    bottom = ee;
    ee = t;
}

void west() {
    int t = top;
    top = ee;
    ee = bottom;
    bottom = ww;
    ww = t;
}

void north() {
    int t = top;
    top = ss;
    ss = bottom;
    bottom = nn;
    nn = t;
}

void south() {
    int t = top;
    top = nn;
    nn = bottom;
    bottom = ss;
    ss = t;
}

int main()
{
    int k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            scanf("%d", &mapp[i][j]);
        }
    }
    top = 1, bottom = 6;
    ee = 3, ww = 4, nn = 2, ss = 5;
    
    int t;
    while(k--) {
        scanf("%d", &t);
        if(t == 1 && isin(x, y+1)) {
            east();
            if(mapp[x][y+1] == 0)
                mapp[x][y+1] = dice[bottom];
            else dice[bottom] = mapp[x][y+1], mapp[x][y+1] = 0;
            y++;
            printf("%d\n", dice[top]);
        }
        else if(t == 2 && isin(x, y-1)) {
            west();
            if(mapp[x][y-1] == 0)
                mapp[x][y-1] = dice[bottom];
            else dice[bottom] = mapp[x][y-1], mapp[x][y-1] = 0;
            y--;
            printf("%d\n", dice[top]);
        }
        else if(t == 3 && isin(x-1, y)) {
            north();
            if(mapp[x-1][y] == 0)
                mapp[x-1][y] = dice[bottom];
            else dice[bottom] = mapp[x-1][y], mapp[x-1][y] = 0;
            x--;
            printf("%d\n", dice[top]);
        }
        else if(t == 4 && isin(x+1, y)) {
            south();
            if(mapp[x+1][y] == 0)
                mapp[x+1][y] = dice[bottom];
            else dice[bottom] = mapp[x+1][y], mapp[x+1][y] = 0;
            x++;
            printf("%d\n", dice[top]);
        }
    }
}