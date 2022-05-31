#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

vector<int> path[MAX];
int cap[MAX][MAX], f[MAX][MAX], d[MAX][MAX];
int res;

void addPath(int st, int en, int val) {
    path[st].push_back(en);
    path[en].push_back(st);
    cap[st][en] = val;
}

void reset(int v) {
    for (int i = 1; i <= v; i++) {
        path[i].clear();
        for (int j = 1; j <= v; j++) {
            cap[i][j] = f[i][j] = d[i][j] = 0;
        }
    }
    res = 0;
}

void mcmf(int st, int en) {
    while (true) {
        vector<int> prev(MAX, -1);
        vector<int> dist(MAX, 1e9);
        vector<bool> vis(MAX, false);
        queue<int> q;

        q.push(st);
        dist[st] = 0;
        vis[st] = true;

        while (!q.empty()) {
            int qf = q.front();
            q.pop();

            vis[qf] = false;
            for (int i = 0; i < path[qf].size(); i++) {
                int nxt = path[qf][i];
                if (cap[qf][nxt] - f[qf][nxt] &&
                    dist[nxt] > dist[qf] + d[qf][nxt]) {
                    dist[nxt] = dist[qf] + d[qf][nxt];
                    prev[nxt] = qf;
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (prev[en] == -1) break;

        int flow = 1e9;
        for (int i = en; i != st; i = prev[i]) {
            flow = min(flow, cap[prev[i]][i] - f[prev[i]][i]);
        }
        for (int i = en; i != st; i = prev[i]) {
            res += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
    }
}

int main() {
    for (int ttt = 0; ttt < 2; ttt++) {
        int v, e;
        scanf("%d %d", &v, &e);
        for (int i = 0; i < e; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            addPath(a, b, 1);
            d[a][b] += c;
            d[b][a] += -c;
        }
        mcmf(1, v);
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                printf("%2d ", f[i][j]);
            }
            puts("");
        }
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                printf("%2d ", cap[i][j]);
            }
            puts("");
        }
        printf("%d\n", res);
        if (!ttt) reset(v);
    }
}