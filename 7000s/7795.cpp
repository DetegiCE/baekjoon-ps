#include <bits/stdc++.h>
using namespace std;

void sol() {
    int a, b;
    vector<int> n, m;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++) {
        int t;
        scanf("%d", &t);
        n.push_back(t);
    }
    for (int i = 0; i < b; i++) {
        int t;
        scanf("%d", &t);
        m.push_back(t);
    }
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());
    int s = 0;
    for (int i = 0; i < b; i++) {
        s += a - (lower_bound(n.begin(), n.end(), m[i] + 1) - n.begin());
    }
    printf("%d\n", s);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        sol();
    }
}