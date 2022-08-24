#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int min6 = 1001, min1 = 1001;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        min6 = min(min6, a);
        min1 = min(min1, b);
    }

    int c1 = n * min1;
    int c2 = (n % 6 ? n / 6 * min6 + n % 6 * min1 : n / 6 * min6);
    int c3 = (n % 6 ? (n / 6 + 1) * min6 : n / 6 * min6);
    printf("%d\n", min(min(c1, c2), c3));
}