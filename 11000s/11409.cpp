#include <bits/stdc++.h>
using namespace std;

#define MAX 803
#define INF 1e9

vector<int> path[MAX];
int cap[MAX][MAX], f[MAX][MAX], d[MAX][MAX];
int res, cnt;

void addPath(int st, int en, int val) {
    path[st].push_back(en);
    path[en].push_back(st);
    cap[st][en] = val;
}

void mcmf(int start, int end) {
    while (true) {
        vector<int> prev(MAX, -1);
        vector<int> dist(MAX, INF);
        vector<bool> vis(MAX, false);
        queue<int> q;

        q.push(start);
        dist[start] = 0;
        vis[start] = true;

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

        if (prev[end] == -1) break;

        int flow = INF;
        for (int i = end; i != start; i = prev[i]) {
            flow = min(flow, cap[prev[i]][i] - f[prev[i]][i]);
        }
        for (int i = end; i != start; i = prev[i]) {
            res += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        cnt++;
    }
}

int main() {
    // start : 0
    // human: 1 ~ 400
    // work: 401 ~ 800
    // sink: 801
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        addPath(0, i, 1);
        int s;
        scanf("%d", &s);
        while (s--) {
            int t, c;
            scanf("%d %d", &t, &c);
            addPath(i, 400 + t, 1);
            d[i][400 + t] = -c;
            d[400 + t][i] = c;
        }
    }
    for (int i = 1; i <= m; i++) {
        addPath(400 + i, 801, 1);
    }

    mcmf(0, 801);

    printf("%d\n%d", cnt, -res);
}