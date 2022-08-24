#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int ncr(int n, int r) {
    int a = 1;
    for (int i = 1; i <= n; i++) a *= i;
    for (int i = 1; i <= r; i++) a /= i;
    for (int i = 1; i <= n - r; i++) a /= i;
    return a;
}

void makePool(int dig, int pos, int cur) {
    if (dig == pos) {
        v.push_back(cur);
        return;
    }
    for (int i = cur % 10 - 1; i >= dig - pos - 1; i--) {
        makePool(dig, pos + 1, cur * 10 + i);
    }
}

int main() {
    int n;
    int cnt[11];
    for (int i = 1; i <= 10; i++) cnt[i] = ncr(10, i);
    scanf("%d", &n);
    if (n < 10) {
        printf("%d", n);
        return 0;
    }
    if (n == 1022) {
        puts("9876543210");
        return 0;
    }

    int ac = cnt[1];
    for (int i = 2; i <= 10; i++) {
        if (ac <= n && n < ac + cnt[i]) {
            for (int j = i - 1; j <= 9; j++) {
                makePool(i, 1, j);
            }
            sort(v.begin(), v.end());
            printf("%d\n", v[n - ac]);
            return 0;
        }
        ac += cnt[i];
    }
    puts("-1");
    return 0;
}