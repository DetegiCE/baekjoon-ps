#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 203
#define INF 1e9
#define MIN(A,B) (A>B?B:A)

int n, m, result;
int cap[MAX][MAX], f[MAX][MAX], vis[MAX];
vector<int> path[MAX];

void addPath(int st, int en, int val) {
    path[st].push_back(en);
    path[en].push_back(st);
    cap[st][en] = val;
}

void maxFlow(int start, int end) {
    while (1) {
        fill(vis, vis + MAX, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < path[x].size(); i++) {
                int y = path[x][i];
                if (cap[x][y] - f[x][y] > 0 && vis[y] == -1) {
                    q.push(y);
                    vis[y] = x;
                    if (y == end) {
                        break;
                    }
                }
            }
        }
        if (vis[end] == -1) break;
        int flow = INF;
        for (int i = end; i != start; i = vis[i]) {
            flow = MIN(flow, cap[vis[i]][i] - f[vis[i]][i]);
        }
        for (int i = end; i != start; i = vis[i]) {
            f[vis[i]][i] += flow;
            f[i][vis[i]] -= flow;
        }
        result += flow;
    }
}

int main() {
    // start: 0
    // store: 1 ~ 100
    // human: 101 ~ 200
    // sink: 201
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        int t;
        scanf("%d", &t);
        addPath(i+100, 201, t);
    }
    for(int i=1 ; i<=m ; i++) {
        int t;
        scanf("%d", &t);
        addPath(0, i, t);
    }
    for(int i=1 ; i<=m ; i++) {
        for(int j=1 ; j<=n ; j++) {
            int t;
            scanf("%d", &t);
            addPath(i, j+100, t);
        }
    }
    maxFlow(0, 201);
    printf("%d", result);
}
