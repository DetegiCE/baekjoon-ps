// 에드몬드 카프 O(VE^2)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100
#define INF 1e9
#define MIN(A,B) (A>B?B:A)

int n = 6, result;
int cap[MAX][MAX], f[MAX][MAX], vis[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end) {
    while (1) {
        fill(vis, vis + MAX, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];
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
            flow = MIN(flow, c[vis[i]][i] - f[vis[i]][i]);
        }
        for (int i = end; i != start; i = vis[i]) {
            f[vis[i]][i] += flow;
            f[i][vis[i]] -= flow;
        }
        result += flow;
    }
}

int main() {
    maxFlow(1, 6);
    printf("%d", result);
}