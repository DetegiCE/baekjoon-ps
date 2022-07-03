#include <cstdio>

int cnt[11];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        int num[11] = {0};
        for (int j = 0; j < 6; j++) {
            scanf("%1d", &t);
            num[t]++;
        }
        for (int j = 0; j < 10; j++) {
            if (num[j] > 0) cnt[j]++;
        }
    }
}