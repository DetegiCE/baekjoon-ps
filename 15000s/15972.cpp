#include <bits/stdc++.h>
using namespace std;

#define MAX 1003

struct hole {
    int link;
    int height;
    bool operator<(const hole &t) const { return height > t.height; }
};

int n, m, h;
int tank[MAX][MAX];
vector<hole> path[MAX * MAX];

inline int c2n(int y, int x) { return (y - 1) * m + x; }
inline pair<int, int> n2c(int x) { return {(x - 1) / m + 1, (x - 1) % m + 1}; }

void makePath(int st, int en, int val) {
    path[st].push_back({en, val});
    path[en].push_back({st, val});
}

int main() {
    int t;
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t);
            if (i == 0) {
                if (t != -1) makePath(0, j, t);
            } else if (i == n) {
                if (t != -1) makePath(0, c2n(i, j), t);
            } else {
                if (t != -1) makePath(c2n(i, j), c2n(i + 1, j), t);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            tank[i][j] = h;
            scanf("%d", &t);
            if (j == 0) {
                if (t != -1) makePath(0, c2n(i, 1), t);
            } else if (j == m) {
                if (t != -1) makePath(0, c2n(i, j), t);
            } else {
                if (t != -1) makePath(c2n(i, j), c2n(i, j + 1), t);
            }
        }
    }

    // for (int i = 0; i <= n * m; i++) {
    //     printf("%d: ", i);
    //     for (int j = 0; j < path[i].size(); j++) {
    //         printf("(%d, %d) ", path[i][j].link, path[i][j].height);
    //     }
    //     puts("");
    // }

    priority_queue<hole> q;
    q.push({0, 0});
    tank[0][0] = 0;
    while (!q.empty()) {
        int ql = q.top().link;
        int qh = q.top().height;
        // printf("(%d, %d) ", ql, qh);
        q.pop();

        pair<int, int> fc = n2c(ql);
        // printf("= (%d, %d [%d])\n", fc.first, fc.second,
        //    tank[fc.first][fc.second]);
        if (tank[fc.first][fc.second] < qh) continue;
        for (int j = 0; j < path[ql].size(); j++) {
            // printf("-- (%d, %d)\n", path[ql][j].link, path[ql][j].height);
            pair<int, int> nxt = n2c(path[ql][j].link);
            if (max(qh, path[ql][j].height) < tank[nxt.first][nxt.second]) {
                tank[nxt.first][nxt.second] = max(qh, path[ql][j].height);
                q.push({path[ql][j].link, tank[nxt.first][nxt.second]});
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // printf("%d ", tank[i][j]);
            sum += tank[i][j];
        }
        // puts("");
    }
    printf("%d", sum);
}