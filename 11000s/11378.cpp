#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 2004
#define MIN(A,B) (A>B?B:A)

int cap[MAX][MAX], f[MAX][MAX], vis[MAX], result;
vector<int> path[MAX];

void makePath(int start, int end, int val) {
    path[start].push_back(end);
    path[end].push_back(start);
    cap[start][end] = val;
}

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
                    vis[nxt] = qf;
                    q.push(nxt);
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
    // first start : 0
    // second start: 2001
    // human: 1 ~ 1000
    // work: 1001 ~ 2000
    // sink: 2002
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    makePath(0, 2001, k);
    for(int i=1 ; i<=n ; i++) {
        makePath(0, i, 1);
        makePath(2001, i, k);
        int s;
        scanf("%d", &s);
        while(s--) {
            int t;
            scanf("%d", &t);
            makePath(i, 1000+t, 1);
        }
    }
    for(int i=1 ; i<=m ; i++) {
        makePath(i+1000, 2002, 1);
    }
    maxFlow(0, 2002);
    printf("%d", result);
}