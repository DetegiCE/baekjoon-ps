#include <cmath>
#include <cstdio>
#include <cstring>

char st[1001];
char p[35][35];
bool vis[35][35];

int main() {
    scanf("%s", st);
    int slen = strlen(st);
    int ssqrt = sqrt(slen);
    for (int i = 0; i <= ssqrt + 1; i++) {
        for (int j = 0; j <= ssqrt + 1; j++) {
            p[i][j] = '.';
        }
    }
    int cnt = 0;
    for (int i = 1; i <= ssqrt; i++) {
        for (int j = 1; j <= ssqrt; j++) {
            p[i][j] = st[cnt++];
        }
    }
    for (int i = 1; i <= ssqrt / 2; i++) {
        for (int j = 1; j <= ssqrt / 2 - i + 1; j++) {
            p[i][j] = '.';
            p[i][ssqrt - j + 1] = '.';
            p[ssqrt - i + 1][j] = '.';
            p[ssqrt - i + 1][ssqrt - j + 1] = '.';
        }
    }

    int posy = ssqrt / 2 + 1;
    int posx = 1;
    for (int i = posy - 2; i >= 0; i--) {
        for (int dir = 0; dir < 4; dir++) {
            for (int j = 0; j <= i; j++) {
                printf("%c", p[posy][posx]);
                if (dir == 0) {
                    posy--, posx++;
                } else if (dir == 1) {
                    posy++, posx++;
                } else if (dir == 2) {
                    posy++, posx--;
                } else {
                    if (j == i) {
                        posy--;
                        continue;
                    }
                    posy--, posx--;
                }
            }
        }
    }
    printf("%c", p[ssqrt / 2 + 1][ssqrt / 2 + 1]);
}

/*
JOMHN
PARTA
ILUUH
LASER
INWGO
*/