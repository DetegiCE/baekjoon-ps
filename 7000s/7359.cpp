#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

#define MP(A, B) make_pair(A, B)

typedef pair<int, int> pii;

queue<pii> q;

bool success = true;
void crush(int mv) {
    printf("The worm ran into itself on move %d.\n", mv);
    success = false;
}
void outbound(int mv) {
    printf("The worm ran off the board on move %d.\n", mv);
    success = false;
}

int main() {
    while (true) {
        int n;
        char mv[102];
        bool board[52][52] = {false};
        int cx = 30, cy = 25;
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", mv);
        for (int i = 11; i <= 30; i++) {
            q.push(MP(i, 25));
            board[i][25] = true;
        }

        success = true;
        for (int i = 0; i < n; i++) {
            if (mv[i] == 'N') {
                if (board[cx][cy - 1]) {
                    crush(i + 1);
                    break;
                }
                if (cy == 1) {
                    outbound(i + 1);
                    break;
                }
                q.pop();
                board[q.front().first][q.front().second] = false;
                cy--;
                q.push(MP(cx, cy));
                board[cx][cy] = true;
            }
            if (mv[i] == 'S') {
                if (board[cx][cy + 1]) {
                    crush(i + 1);
                    break;
                }
                if (cy == 50) {
                    outbound(i + 1);
                    break;
                }
                q.pop();
                board[q.front().first][q.front().second] = false;
                cy++;
                q.push(MP(cx, cy));
                board[cx][cy] = true;
            }
            if (mv[i] == 'E') {
                if (board[cx + 1][cy]) {
                    crush(i + 1);
                    break;
                }
                if (cx == 50) {
                    outbound(i + 1);
                    break;
                }
                q.pop();
                board[q.front().first][q.front().second] = false;
                cx++;
                q.push(MP(cx, cy));
                board[cx][cy] = true;
            }
            if (mv[i] == 'W') {
                if (board[cx - 1][cy]) {
                    crush(i + 1);
                    break;
                }
                if (cx == 1) {
                    outbound(i + 1);
                    break;
                }
                q.pop();
                board[q.front().first][q.front().second] = false;
                cx--;
                q.push(MP(cx, cy));
                board[cx][cy] = true;
            }
        }
        if (success) {
            printf("The worm successfully made all %d moves.\n", n);
        }
    }
}