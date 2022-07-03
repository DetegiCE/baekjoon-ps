#include <cstdio>

int n;

int s5[6][6] = {{0, 1, 0, 2, 3},
                {0, 2, 3, 0, 1},
                {1, 3, 0, 0, 2},
                {3, 0, 2, 1, 0},
                {2, 0, 1, 3, 0}};
int s6[7][7] = {{1, 2, 0, 3, 0, 0}, {3, 0, 1, 0, 2, 0}, {0, 0, 0, 2, 3, 1},
                {0, 1, 3, 0, 0, 2}, {0, 3, 2, 1, 0, 0}, {2, 0, 0, 0, 1, 3}};
int s7[8][8] = {{1, 2, 0, 3, 0, 0, 0}, {3, 0, 0, 1, 0, 2, 0},
                {0, 0, 2, 0, 0, 3, 1}, {0, 1, 0, 0, 3, 0, 2},
                {0, 0, 3, 2, 1, 0, 0}, {0, 3, 0, 0, 2, 1, 0},
                {2, 0, 1, 0, 0, 0, 3}};
int s8[9][9] = {{1, 2, 3, 0, 0, 0, 0, 0}, {3, 0, 0, 1, 0, 0, 2, 0},
                {0, 0, 2, 0, 0, 0, 3, 1}, {0, 0, 1, 2, 0, 3, 0, 0},
                {0, 1, 0, 0, 3, 0, 0, 2}, {0, 0, 0, 3, 2, 1, 0, 0},
                {0, 3, 0, 0, 0, 2, 1, 0}, {2, 0, 0, 0, 1, 0, 0, 3}};
int s9[10][10] = {{1, 2, 3, 0, 0, 0, 0, 0, 0}, {3, 0, 0, 1, 0, 0, 0, 2, 0},
                  {0, 0, 2, 0, 0, 0, 0, 3, 1}, {0, 0, 1, 2, 0, 0, 3, 0, 0},
                  {0, 1, 0, 0, 0, 3, 0, 0, 2}, {0, 0, 0, 3, 2, 1, 0, 0, 0},
                  {0, 0, 0, 0, 3, 2, 1, 0, 0}, {0, 3, 0, 0, 0, 0, 2, 1, 0},
                  {2, 0, 0, 0, 1, 0, 0, 0, 3}};
int s10[11][11] = {
    {1, 2, 3, 0, 0, 0, 0, 0, 0, 0}, {3, 0, 0, 1, 0, 0, 0, 0, 2, 0},
    {0, 0, 2, 0, 0, 0, 0, 0, 3, 1}, {0, 1, 0, 2, 0, 0, 0, 3, 0, 0},
    {0, 0, 0, 0, 0, 1, 3, 0, 0, 2}, {0, 0, 0, 0, 3, 2, 0, 1, 0, 0},
    {0, 0, 0, 3, 2, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 3, 2, 0, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 2, 1, 0}, {2, 0, 0, 0, 1, 0, 0, 0, 0, 3}};

int main() {
    scanf("%d", &n);
    if (n == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s5[i][j]);
            puts("");
        }
    } else if (n == 6) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s6[i][j]);
            puts("");
        }
    } else if (n == 7) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s7[i][j]);
            puts("");
        }
    } else if (n == 8) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s8[i][j]);
            puts("");
        }
    } else if (n == 9) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s9[i][j]);
            puts("");
        }
    } else if (n == 10) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", s10[i][j]);
            puts("");
        }
    } else {
        int des = (n - 11) % 6 + 5;
        int cst = (n - des) / 2;
        int cen = (n - des) / 2 + des - 1;
        // printf("%d %d %d\n", des, cst, cen);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < cst) {
                    if (j < cst) {
                        if (i / 3 == j / 3)
                            printf("%d ", s6[i % 3][j % 3]);
                        else
                            printf("0 ");
                    } else if (j > cen) {
                        if (i / 3 == (n - j - 1) / 3)
                            printf("%d ", s6[i % 3][2 - (n - j - 1) % 3 + 3]);
                        else
                            printf("0 ");
                    } else
                        printf("0 ");
                } else if (i > cen) {
                    if (j < cst) {
                        if ((n - i - 1) / 3 == j / 3)
                            printf("%d ", s6[2 - (n - i - 1) % 3 + 3][j % 3]);
                        else
                            printf("0 ");
                    } else if (j > cen) {
                        if ((n - i - 1) / 3 == (n - j - 1) / 3)
                            printf("%d ", s6[2 - (n - i - 1) % 3 + 3]
                                            [2 - (n - j - 1) % 3 + 3]);
                        else
                            printf("0 ");
                    } else
                        printf("0 ");
                } else if (i >= cst && i <= cen) {
                    if (j >= cst && j <= cen) {
                        if (des == 5) printf("%d ", s5[i - cst][j - cst]);
                        if (des == 6) printf("%d ", s6[i - cst][j - cst]);
                        if (des == 7) printf("%d ", s7[i - cst][j - cst]);
                        if (des == 8) printf("%d ", s8[i - cst][j - cst]);
                        if (des == 9) printf("%d ", s9[i - cst][j - cst]);
                        if (des == 10) printf("%d ", s10[i - cst][j - cst]);
                    } else
                        printf("0 ");
                }
            }
            puts("");
        }
    }
}