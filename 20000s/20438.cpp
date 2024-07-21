#include <bits/stdc++.h>
using namespace std;

int n, k, q, m;
int a[5003];
int b[5003], c[5003];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> q >> m;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        a[t] = -1;
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (a[t] == -1) continue;
        for (int j = t; j <= n + 2; j += t) {
            if (a[j] == -1) continue;
            b[j] = 1;
        }
    }
    for (int i = 3; i <= n + 2; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 0; i < m; i++) {
        int r, s;
        cin >> r >> s;
        cout << (s - r + 1) - c[s] + c[r - 1] << '\n';
    }
}