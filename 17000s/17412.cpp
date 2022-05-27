#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 404
#define MIN(A,B) (A>B?B:A)

int cap[MAX][MAX], f[MAX][MAX], vis[MAX], result;
vector<int> path[MAX];

void maxFlow(int start, int end) {
    while(1) {
        fill(vis, vis+MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int qf = q.front(); q.pop();
            for(int i=0 ; i<path[qf].size() ; i++) {
                int nxt = path[qf][i];
                if(cap[qf][nxt] - f[qf][nxt] && vis[nxt] == -1) {
                    q.push(nxt);
                    vis[nxt] = qf;
                    if(nxt == end) break;
                }
            }
        }
        if(vis[end] == -1) break;
        int flow = 1e9;
        for(int i=end ; i!=start ; i=vis[i]) {
            flow = MIN(flow, cap[vis[i]][i] - f[vis[i]][i]);
        }
        for(int i=end ; i!=start ; i=vis[i]) {
            f[vis[i]][i] += flow;
            f[i][vis[i]] -= flow;
        }
        result += flow;
    }
}

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i=0 ; i<p ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a].push_back(b);
        path[b].push_back(a);
        cap[a][b] = 1;
    }
    maxFlow(1, 2);
    printf("%d", result);
}