#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define MAX 2004
#define MIN(A,B) (A>B?B:A)

int n, m, k, result;
vector<int> a[MAX];
int cap[MAX][MAX], f[MAX][MAX], vis[MAX];
// 1st start: 0
// 2nd start: 2001
// people: 1 ~ 1000
// work: 1001 ~ 2000
// sink: 2002

void maxFlow(int start, int end) {
    while(1) {
        fill(vis, vis+MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int qf = q.front(); q.pop();
            for(int i=0 ; i<a[qf].size() ; i++) {
                int nxt = a[qf][i];
                if(cap[qf][nxt] - f[qf][nxt] && vis[nxt] == -1) {
                    q.push(nxt);
                    vis[nxt] = qf;
                    if(nxt == end) break;
                }
            }
        }
        if(vis[end] == -1) break;
        int flow = 1e9;
        for(int i=end ; i!=start ; i = vis[i]) {
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
    scanf("%d %d %d", &n, &m, &k);
    a[0].push_back(2001);
    a[2001].push_back(0);
    cap[0][2001] = k;
    for(int i=1 ; i<=n ; i++) {
        a[0].push_back(i);
        a[i].push_back(0);
        a[2001].push_back(i);
        a[i].push_back(2001);
        cap[0][i] = cap[2001][i] = 1;
        int s;
        scanf("%d", &s);
        while(s--) {
            int t;
            scanf("%d", &t);
            a[i].push_back(t+1000);
            a[t+1000].push_back(i);
            cap[i][t+1000] = 1;
        }
    }
    for(int i=1 ; i<=m ; i++) {
        a[i+1000].push_back(2002);
        a[2002].push_back(i+1000);
        cap[i+1000][2002] = 1;
    }
    maxFlow(0, 2002);
    printf("%d", result);
}