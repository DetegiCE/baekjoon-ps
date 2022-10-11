#include <bits/stdc++.h>
using namespace std;

int n, t;
int mapp[1001][1001];
bool iss[1001];

typedef struct city {
    int idx;
    int r;
    int c;

    city(int idx, int r, int c) : idx(idx), r(r), c(c) {}
} CITY;

vector<CITY> v;

inline int getdiff(int a, int b) {
    return abs(v[a].r - v[b].r) + abs(v[a].c - v[b].c);
}

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.emplace_back(i, b, c);
        iss[i] = a;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mapp[i][j] = 999999999;
            if (i ^ j) {
                if (iss[i] && iss[j]) mapp[i][j] = min(mapp[i][j], t);
                mapp[i][j] = min(mapp[i][j], getdiff(i, j));
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i ^ j && mapp[i][j] > mapp[i][k] + mapp[k][j])
                    mapp[i][j] = mapp[i][k] + mapp[k][j];
            }
        }
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", mapp[a - 1][b - 1]);
    }
}