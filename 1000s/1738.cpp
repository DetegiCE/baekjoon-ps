#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
#define MP(A,B) make_pair(A,B)

int n, m;
vector<ppi> edge;
vector<int> rlnk[102];
int dst[102], par[102], vis[102];
int isCycle;

queue<int> q;

void chk(int pos) {
    if(pos == 1) {
        cout << 1 << ' ';
        return;
    }
    chk(par[pos]);
    cout << pos << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(MP(MP(u, v), -w));
        rlnk[v].push_back(u);
    }
    for(int i=1 ; i<=n ; i++) {
        dst[i] = 1e9;
    }
    dst[1] = 0;
    par[1] = 1;
    
    q.push(n);
    vis[n] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt: rlnk[cur]) {
            if(!vis[nxt]) {
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=0 ; j<m ; j++) {
            int fr = edge[j].first.first;
            int to = edge[j].first.second;
            int cst = edge[j].second;
            
            if(dst[fr] == 1e9) continue;
            if(dst[to] > dst[fr] + cst) {
                if(i == n && vis[fr]) isCycle = true;
                dst[to] = dst[fr] + cst;
                par[to] = fr;
            }
        }
    }
    
    if(isCycle) {
        cout << -1;
        return 0;
    }
    
    chk(n);
}
