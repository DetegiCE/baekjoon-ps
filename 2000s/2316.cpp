#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 808
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
    // in 1 ~ 400 out 401~800
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i=3 ; i<=n ; i++) {
        path[i].push_back(i+400);
        path[i+400].push_back(i);
        cap[i][i+400] = 1;
    }
    for(int i=0 ; i<p ; i++) {
        int a, b, t;
        scanf("%d %d", &a, &b);
        if(a > b) t=a,a=b,b=t;
        if(a == 1) {
            path[401].push_back(b);
            path[b].push_back(401);
            cap[401][b] = 1;
            continue;
        }
        if(a == 2) {
            path[2].push_back(400+b);
            path[b+400].push_back(2);
            cap[400+b][2] = 1;
            continue;
        }
        path[a+400].push_back(b);
        path[b].push_back(a+400);
        path[b+400].push_back(a);
        path[a].push_back(b+400);
        cap[a+400][b] = 1;
        cap[b+400][a] = 1;
    }
    maxFlow(401, 2);
    printf("%d", result);
}