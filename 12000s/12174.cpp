#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        int n;
        char b[8001];
        scanf("%d", &n);
        scanf(" %s", b);
        int s = 0;
        for (int j = 0; j < n * 8; j++) {
            s *= 2;
            s += (b[j] == 'O' ? 0 : 1);
            if (j % 8 == 7) {
                printf("%c", s);
                s = 0;
            }
        }
        puts("");
    }
}