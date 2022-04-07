#include <cstdio>
#include <queue>
using namespace std;

int board[101][101];

int time[101];
char pos[101];

queue<int> qx;
queue<int> qy;

int main() {
    int n, k, l;
    int lookup = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x][y] = 2;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf(" %d %c", &time[i], &pos[i]);
    }

    char dir = 'R';
    int posx = 1;
    int posy = 1;
    int curtime = 0;
    board[1][1] = 1;
    qx.push(1);
    qy.push(1);
    while (true) {
        // printf("%d %d %d %c\n", curtime, posx, posy, dir);
        if (dir == 'R') {
            if (posy + 1 > n || board[posx][posy + 1] == 1) {
                printf("%d", curtime + 1);
                return 0;
            }
            if (board[posx][posy + 1] == 2) {
                board[posx][posy + 1] = 1;
                qx.push(posx);
                qy.push(posy + 1);
                posy++;
            } else {
                board[posx][posy + 1] = 1;
                board[qx.front()][qy.front()] = 0;
                qx.push(posx);
                qy.push(posy + 1);
                qx.pop();
                qy.pop();
                posy++;
            }
        } else if (dir == 'L') {
            if (posy - 1 < 1 || board[posx][posy - 1] == 1) {
                printf("%d", curtime + 1);
                return 0;
            }
            if (board[posx][posy - 1] == 2) {
                board[posx][posy - 1] = 1;
                qx.push(posx);
                qy.push(posy - 1);
                posy--;
            } else {
                board[posx][posy - 1] = 1;
                board[qx.front()][qy.front()] = 0;
                qx.push(posx);
                qy.push(posy - 1);
                qx.pop();
                qy.pop();
                posy--;
            }
        } else if (dir == 'U') {
            if (posx - 1 < 1 || board[posx - 1][posy] == 1) {
                printf("%d", curtime + 1);
                return 0;
            }
            if (board[posx - 1][posy] == 2) {
                board[posx - 1][posy] = 1;
                qx.push(posx - 1);
                qy.push(posy);
                posx--;
            } else {
                board[posx - 1][posy] = 1;
                board[qx.front()][qy.front()] = 0;
                qx.push(posx - 1);
                qy.push(posy);
                qx.pop();
                qy.pop();
                posx--;
            }
        } else {
            if (posx + 1 > n || board[posx + 1][posy] == 1) {
                printf("%d", curtime + 1);
                return 0;
            }
            if (board[posx + 1][posy] == 2) {
                board[posx + 1][posy] = 1;
                qx.push(posx + 1);
                qy.push(posy);
                posx++;
            } else {
                board[posx + 1][posy] = 1;
                board[qx.front()][qy.front()] = 0;
                qx.push(posx + 1);
                qy.push(posy);
                qx.pop();
                qy.pop();
                posx++;
            }
        }
        curtime++;
        if (time[lookup] == curtime) {
            if (pos[lookup] == 'L') {
                if (dir == 'U')
                    dir = 'L';
                else if (dir == 'L')
                    dir = 'D';
                else if (dir == 'D')
                    dir = 'R';
                else
                    dir = 'U';
            } else {
                if (dir == 'U')
                    dir = 'R';
                else if (dir == 'R')
                    dir = 'D';
                else if (dir == 'D')
                    dir = 'L';
                else
                    dir = 'U';
            }
            lookup++;
        }
    }
}