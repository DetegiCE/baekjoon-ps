#include <bits/stdc++.h>
using namespace std;

vector<int> path[100001];
bool vis[100001];
int cnt = 0;
int ord[100001];

void dfs(int node) {
    ord[node] = ++cnt;
    vis[node] = true;
    for (int i = 0; i < path[node].size(); i++) {
        int nxt = path[node][i];
        if (!vis[nxt]) dfs(nxt);
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(path[i].begin(), path[i].end());
    }
    dfs(r);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ord[i]);
    }
}