#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

char puyo[13][7];
int pops[13][7];
int grno;
int grcnt[80];
bool curpop[13][7];
int chain;

void reset() {
    grno = 0;
    for(int i=0 ; i<12 ; i++) {
        for(int j=0 ; j<6 ; j++) {
            pops[i][j] = 0;
            curpop[i][j] = false;
        }
    }
    for(int i=0 ; i<80 ; i++) grcnt[i] = 0;
}

inline bool inb(int y, int x) {
    return 0 <= y && y < 12 && 0 <= x && x < 6;
}

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

void dfs(int y, int x) {
    pops[y][x] = grno;
    for(int i=0 ; i<4 ; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(inb(ny, nx) && puyo[ny][nx] == puyo[y][x] && pops[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main()
{
    INP;
    
    for(int i=0 ; i<12 ; i++) {
        scanf("%s", puyo[i]);
    }
    while(1) {
        reset();
        bool haschain = false;
        
        for(int i=0 ; i<12 ; i++) {
            for(int j=0 ; j<6 ; j++) {
                if(puyo[i][j] != '.' && pops[i][j] == 0) {
                    grno++;
                    dfs(i, j);
                }
            }
        }
        for(int i=0 ; i<12 ; i++) {
            for(int j=0 ; j<6 ; j++) {
                if(pops[i][j] == 0) continue;
                grcnt[pops[i][j]]++;
            }
        }
        for(int i=0 ; i<12 ; i++) {
            for(int j=0 ; j<6 ; j++) {
                if(grcnt[pops[i][j]] >= 4) {
                    curpop[i][j] = true;
                    haschain = true;
                }
            }
        }
        
        if(!haschain) break;
        chain++;
        for(int i=0 ; i<12 ; i++) {
            for(int j=0 ; j<6 ; j++) {
                if(curpop[i][j]) puyo[i][j] = '.';
            }
        }
        
        for(int k=0 ; k<12 ; k++) {
            for(int i=11 ; i>=1 ; i--) {
                for(int j=0 ; j<6 ; j++) {
                    if(puyo[i][j] == '.' && puyo[i-1][j] != '.') {
                        puyo[i][j] = puyo[i-1][j];
                        puyo[i-1][j] = '.';
                    }
                }
            }
        }
    }
    printf("%d", chain);
}