#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAX 1003

struct coord {
    int x, y;
};

int n, m, k;
int x1, yy1, x2, y2;
bool mapp[MAX][MAX];
int elap[MAX][MAX];
queue<coord> q;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            elap[i][j] = 1e9;
            mapp[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        char ma[MAX];
        scanf("%s", &ma[1]);
        for (int j = 1; j <= m; j++) {
            if (ma[j] == '.')
                mapp[i][j] = true;
            else
                mapp[i][j] = false;
        }
    }
    scanf("%d %d %d %d", &x1, &yy1, &x2, &y2);
    elap[x1][yy1] = 0;
    q.push({x1, yy1});
    while (!q.empty()) {
        int qfx = q.front().x;
        int qfy = q.front().y;
        q.pop();
        // printf("%d %d\n", qfx, qfy);
        // go right
        for (int i = 1; i <= k; i++) {
            int nxy = qfy + i;
            if (nxy > m) break;
            // printf("-- R %d %d %d\n", qfx, nxy, elap[qfx][nxy]);
            if (!mapp[qfx][nxy]) {
                break;
            }
            if (elap[qfx][nxy] < elap[qfx][qfy] + 1) break;
            if (elap[qfx][nxy] > elap[qfx][qfy] + 1) {
                if (elap[qfx][nxy] == 1e9) {
                    q.push({qfx, nxy});
                }
                elap[qfx][nxy] = elap[qfx][qfy] + 1;
                if (qfx == x2 && nxy == y2) {
                    printf("%d", elap[qfx][nxy]);
                    return 0;
                }
            }
        }

        // go left
        for (int i = 1; i <= k; i++) {
            int nxy = qfy - i;
            if (nxy < 1) break;
            // printf("-- L %d %d\n", qfx, nxy);
            if (!mapp[qfx][nxy]) {
                break;
            }
            if (elap[qfx][nxy] < elap[qfx][qfy] + 1) break;
            if (elap[qfx][nxy] > elap[qfx][qfy] + 1) {
                if (elap[qfx][nxy] == 1e9) {
                    q.push({qfx, nxy});
                }
                elap[qfx][nxy] = elap[qfx][qfy] + 1;
                if (qfx == x2 && nxy == y2) {
                    printf("%d", elap[qfx][nxy]);
                    return 0;
                }
            }
        }

        // go up
        for (int i = 1; i <= k; i++) {
            int nxx = qfx - i;
            if (nxx < 1) break;
            // printf("-- U %d %d\n", nxx, qfy);
            if (!mapp[nxx][qfy]) {
                break;
            }
            if (elap[nxx][qfy] < elap[qfx][qfy] + 1) break;
            if (elap[nxx][qfy] > elap[qfx][qfy] + 1) {
                if (elap[nxx][qfy] == 1e9) {
                    q.push({nxx, qfy});
                }
                elap[nxx][qfy] = elap[qfx][qfy] + 1;
                if (nxx == x2 && qfy == y2) {
                    printf("%d", elap[nxx][qfy]);
                    return 0;
                }
            }
        }

        // go down
        for (int i = 1; i <= k; i++) {
            int nxx = qfx + i;
            if (nxx > n) break;
            // printf("-- D %d %d\n", nxx, qfy);
            if (!mapp[nxx][qfy]) {
                break;
            }
            if (elap[nxx][qfy] < elap[qfx][qfy] + 1) break;
            if (elap[nxx][qfy] > elap[qfx][qfy] + 1) {
                if (elap[nxx][qfy] == 1e9) {
                    q.push({nxx, qfy});
                }
                elap[nxx][qfy] = elap[qfx][qfy] + 1;
                if (nxx == x2 && qfy == y2) {
                    printf("%d", elap[nxx][qfy]);
                    return 0;
                }
            }
        }
    }

    printf("%d", elap[x2][y2] == 1e9 ? -1 : elap[x2][y2]);
}