#include <cstdio>

int arr[1030][1030];
int acc[1030][1030];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            if (!i)
                acc[i][j] = arr[i][j];
            else if (!j)
                acc[i][j] = arr[i][j];
            else
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] +
                            arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", acc[x2][y2] - acc[x2][y1 - 1] - acc[x1 - 1][y2] +
                           acc[x1 - 1][y1 - 1]);
    }
}