#include<bits/stdc++.h>
using namespace std;

int n;
char board[51][51];
int mx;

void flip(int y, int x, int dir) {
    char t;
    if(dir == 0) {
        t = board[y][x];
        board[y][x] = board[y][x+1];
        board[y][x+1] = t;
    }
    else {
        t = board[y+1][x];
        board[y+1][x] = board[y][x];
        board[y][x] = t;
    }
}

int check(int y, int x, int dir) {
    char orig = board[y][x];
    if(dir == 0) {
        int cnt = 1;
        for(int i=y-1 ; i>=0 ; i--) {
            if(board[i][x] == orig) {
                cnt++;
            }
            else break;
        }
        for(int i=y+1 ; i<n ; i++) {
            if(board[i][x] == orig) {
                cnt++;
            }
            else break;
        }
        return cnt;
    }
    else {
        int cnt = 1;
        for(int i=x-1 ; i>=0 ; i--) {
            if(board[y][i] == orig) {
                cnt++;
            }
            else break;
        }
        for(int i=x+1 ; i<n ; i++) {
            if(board[y][i] == orig) {
                cnt++;
            }
            else break;
        }
        return cnt;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", board[i]);
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            mx = max(mx, check(i, j, 0));
            mx = max(mx, check(i, j, 1));
        }
    }
    // printf("T %d\n", mx);
    // 가로 뒤집기
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n-1 ; j++) {
            flip(i, j, 0);
            mx = max(mx, check(i, j, 0));
            mx = max(mx, check(i, j+1, 0));
            mx = max(mx, check(i, j, 1));
            mx = max(mx, check(i, j+1, 1));
            flip(i, j, 0);
            // printf("H %d %d %d\n", i, j, mx);
        }
    }
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<n ; j++) {
            flip(i, j, 1);
            mx = max(mx, check(i, j, 1));
            mx = max(mx, check(i+1, j, 1));
            mx = max(mx, check(i, j, 0));
            mx = max(mx, check(i+1, j, 0));
            flip(i, j, 1);
            // printf("V %d %d %d\n", i, j, mx);
        }
    }
    printf("%d", mx);
}