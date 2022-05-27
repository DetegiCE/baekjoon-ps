#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 53

int n;
int cap[MAX][MAX], f[MAX][MAX], vis[MAX];
int result;

vector<int> path[MAX];

void maxFlow(int start, int end) {
    while (1) {
        fill(vis, vis + MAX, -1);
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

int getID(char a) { return a <= 'Z' ? a - 'A' : a - 'a' + 26; }

int main() {
    scanf("%d", &n);
    while (n--) {
        char a, b;
        int c;
        scanf(" %c %c %d", &a, &b, &c);
        int aid = getID(a);
        int bid = getID(b);
        path[aid].push_back(bid);
        path[bid].push_back(aid);
        cap[aid][bid] += c;
        cap[bid][aid] += c;
    }
    maxFlow(0, 25);
    printf("%d", result);
}