#include <bits/stdc++.h>
using namespace std;

#define MAX 203
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
    }
}

int main() {
    // start : 0
    // library: 1 ~ 100
    // human: 101 ~ 200
    // sink: 201
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        int t;
        
        scanf("%d", &t);
        addPath(i+100, 201, t);
        d[i+100][201] = 0;
        d[201][i+100] = 0;
    }
    for(int i=1 ; i<=m ; i++) {
        int t;
        
        scanf("%d", &t);
        addPath(0, i, t);
        d[0][i] = 0;
        d[i][0] = 0;
    }
    for(int i=1 ; i<=m ; i++) {
        for(int j=1 ; j<=n ; j++) {
            int t;
            scanf("%d", &t);
            addPath(i, 100+j, INF);
            d[i][100+j] = t;
            d[100+j][i] = -t;
        }
    }

    mcmf(0, 201);

    printf("%d", res);
}