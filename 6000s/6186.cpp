#include<bits/stdc++.h>
using namespace std;

int r, c;
char mapp[101][101];
int group[101][101];
int gcnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int y, int x) {
    group[y][x] = gcnt;
    for(int i=0 ; i<4 ; i++) {
        int nxy = y + dy[i];
        int nxx = x + dx[i];
        if(nxy >=0 && nxy < r && nxx >= 0 && nxx < c && mapp[nxy][nxx] == '#' && group[nxy][nxx] == 0) {
            dfs(nxy, nxx);
        }
    }
}

int main()
{
    scanf("%d %d", &r, &c);
    for(int i=0 ; i<r ; i++) {
        scanf("%s", mapp[i]);
    }
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(mapp[i][j] == '#' && group[i][j] == 0) {
                gcnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d", gcnt);
}