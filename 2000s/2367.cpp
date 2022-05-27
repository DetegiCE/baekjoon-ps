#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 303
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
    // start 0
    // human 1 ~ 200
    // food 201 ~ 300
    // sink 301
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    for(int i=1 ; i<=n ; i++) {
        path[0].push_back(i);
        path[i].push_back(0);
        cap[0][i] = k;
    }
    for(int i=1 ; i<=d ; i++) {
        int t;
        scanf("%d", &t);
        path[i+200].push_back(301);
        path[301].push_back(i+200);
        cap[i+200][301] = t;
    }
    for(int i=1 ; i<=n ; i++) {
        int s;
        scanf("%d", &s);
        while(s--) {
            int t;
            scanf("%d", &t);
            path[i].push_back(t+200);
            path[t+200].push_back(i);
            cap[i][t+200] = 1;
        }
    }
    maxFlow(0, 301);
    printf("%d", result);
}