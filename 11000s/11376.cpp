#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int result;
vector<int> path[2004];
int cap[2004][2004], f[2004][2004], vis[2004];

void maxFlow(int start, int end) {
    while (1) {
        fill(vis, vis + 2004, -1);
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
        cap[0][i] = 2;
        int s;
        scanf("%d", &s);
        while (s--) {
            int t;
            scanf("%d", &t);
            path[i].push_back(t + 1000);
            path[t + 1000].push_back(i);
            cap[i][t + 1000] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        path[1000 + i].push_back(2001);
        path[2001].push_back(1000 + i);
        cap[1000 + i][2001] = 1;
    }
    maxFlow(0, 2001);
    printf("%d", result);
}