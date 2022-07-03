#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        printf("%d ", n * (n - 1) / 2);
        // 1 2 3 4 5 6 7 8
        // 9 1 10 2
        // 3 4 5 6 7 8 9 10
        for (int j = 1; j <= b; j++) printf("%d ", j);
        for (int j = b + 1, k = 1; j <= n * (n - 1) / 2; j++, k++)
            printf("%d %d ", k, j);
        for (int j = n * (n - 1) / 2 - b + 1; j <= n * (n - 1) / 2; j++)
            printf("%d ", j);
        puts("");
    }
}