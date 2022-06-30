#include <time.h>

#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

struct coord {
    int y, x;
};

int ar[9][15];
queue<coord> q[5];

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int cnt = 0;
int maxs = 0;
int lapmax = 0;

inline bool isin(int y, int x) { return 0 <= y && y < 8 && 0 <= x && x < 14; }

int fnum(int n, int dig, int orig) {
    if (dig == 4) {
        int num = n / 1000;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 14; j++) {
                if (ar[i][j] == num) {
                    q[4].push({i, j});
                    // printf("4 - (%d, %d)\n", i, j);
                }
            }
        }
        if (!q[4].empty())
            return fnum(n % 1000, 3, orig);
        else
            return 0;
    } else if (dig == 3) {
        int num = n / 100;
        while (!q[4].empty()) {
            coord qf = q[4].front();
            q[4].pop();
            for (int i = 0; i < 8; i++) {
                int nxy = qf.y + dy[i];
                int nxx = qf.x + dx[i];
                if (isin(nxy, nxx) && ar[nxy][nxx] == num) {
                    q[3].push({nxy, nxx});
                    // printf("3 - (%d, %d)\n", nxy, nxx);
                }
            }
        }
        if (!q[3].empty())
            return fnum(n % 100, 2, orig);
        else
            return 0;
    } else if (dig == 2) {
        int num = n / 10;
        while (!q[3].empty()) {
            coord qf = q[3].front();
            q[3].pop();
            for (int i = 0; i < 8; i++) {
                int nxy = qf.y + dy[i];
                int nxx = qf.x + dx[i];
                if (isin(nxy, nxx) && ar[nxy][nxx] == num) {
                    q[2].push({nxy, nxx});
                    // printf("2 - (%d, %d, %d, %d)\n", nxy, nxx, orig, num);
                }
            }
        }
        if (!q[2].empty())
            return fnum(n % 10, 1, orig);
        else
            return 0;
    } else if (dig == 1) {
        int num = n;
        while (!q[2].empty()) {
            coord qf = q[2].front();
            q[2].pop();
            for (int i = 0; i < 8; i++) {
                int nxy = qf.y + dy[i];
                int nxx = qf.x + dx[i];
                if (isin(nxy, nxx) && ar[nxy][nxx] == num) {
                    // printf("1 - (%d, %d, %d, %d)\n", nxy, nxx, orig, num);
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}

void f() {
    while (!q[4].empty()) q[4].pop();
    while (!q[3].empty()) q[3].pop();
    while (!q[2].empty()) q[2].pop();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 14; j++) {
            ar[i][j] = rand() % 10;
        }
    }
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 14; j++) {
    //         scanf("%1d", &ar[i][j]);
    //     }
    // }

    int flag = 0;
    for (int i = 1000; i <= 8140; i++) {
        while (!q[4].empty()) q[4].pop();
        while (!q[3].empty()) q[3].pop();
        while (!q[2].empty()) q[2].pop();
        int a = fnum(i, 4, i);
        // break;
        if (a == 0) {
            lapmax = lapmax > i - 1 ? lapmax : i - 1;
            if (i - 1 > maxs) {
                printf("MAX Updated: Point %d\n", i - 1);
                for (int k = 0; k < 8; k++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%d", ar[k][j]);
                    }
                    puts("");
                }
            }
            maxs = maxs > i - 1 ? maxs : i - 1;
            if (i >= 5000) printf("%d Point found at TRY %d\n", i - 1, cnt);
            if (i >= 8100) {
                for (int k = 0; k < 8; k++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%d", ar[k][j]);
                    }
                    puts("");
                }
            }
            break;
        }
        if (i == 8140) {
            flag = 1;
        }
    }
    if (flag == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 14; j++) {
                printf("%d", ar[i][j]);
            }
            puts("");
        }
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        f();
        cnt++;
        if (cnt % 100000 == 0) {
            printf("TRY %d (LAPMAX %d, MAX %d)\n", cnt, lapmax, maxs);
            lapmax = 0;
        }
    }
}