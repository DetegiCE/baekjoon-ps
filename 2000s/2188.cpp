#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int result;
vector<int> path[404];
int cap[404][404], f[404][404], vis[404];

void maxFlow(int start, int end) {
    while (1) {
        fill(vis, vis + 404, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int qf = q.front();
            q.pop();
            for (int i = 0; i < path[qf].size(); i++) {
                int nxt = path[qf][i];
                if (cap[qf][nxt] - f[qf][nxt] && vis[nxt] == -1) {
                    q.push(nxt);
                    vis[nxt] = qf;
                    if (nxt == end) break;
                }
            }
        }
        if (vis[end] == -1) break;
        int flow = 1e9;
        for (int i = end; i != start; i = vis[i]) {
            flow = min(flow, cap[vis[i]][i] - f[vis[i]][i]);
        }
        for (int i = end; i != start; i = vis[i]) {
            f[vis[i]][i] += flow;
            f[i][vis[i]] -= flow;
        }
        result += flow;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        path[0].push_back(i);
        path[i].push_back(0);
        cap[0][i] = 1;
        int s;
        scanf("%d", &s);
        while (s--) {
            int t;
            scanf("%d", &t);
            path[i].push_back(t + 200);
            path[t + 200].push_back(i);
            cap[i][t + 200] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        path[200 + i].push_back(401);
        path[401].push_back(200 + i);
        cap[200 + i][401] = 1;
    }
    maxFlow(0, 401);
    printf("%d", result);
}