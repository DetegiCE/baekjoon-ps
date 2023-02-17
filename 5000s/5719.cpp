#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;
#define INF 1e9

int n, m, s, d;
vector<pii> path[501];
vector<int> from[501];
int dst[501], rdst[501];
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool vis[501][501];
bool viscvis[501];

void vischeck(int cur) {
    if(viscvis[cur]) return;
    for(auto k: from[cur]) {
        vis[k][cur] = true;
    }
    viscvis[cur] = true;
    for(auto k: from[cur]) {
        vischeck(k);
    }
}

void f() {
    cin >> s >> d;
    for(int i=0 ; i<n ; i++) {
        path[i].clear();
        dst[i] = INF;
        rdst[i] = INF;
        from[i].clear();
        viscvis[i] = false;
        for(int j=0 ; j<n ; j++)
            vis[i][j] = false;
    }
    for(int i=0 ; i<m ; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        path[u].PB(MP(v, p));
    }
    
    dst[s] = 0;
    pq.push(MP(0, s));
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cdst = pq.top().first;
        pq.pop();
        
        for(auto nn: path[cur]) {
            int nxt = nn.first;
            int ndst = nn.second;
            if(dst[nxt] > dst[cur] + ndst) {
                dst[nxt] = dst[cur] + ndst;
                from[nxt].clear();
                from[nxt].PB(cur);
                pq.push(MP(dst[cur] + ndst, nxt));
            }
            else if(dst[nxt] == dst[cur] + ndst) {
                from[nxt].PB(cur);
            }
        }
    }
    
    vischeck(d);
    
    // cout << "DST "; for(int i=0 ; i<n ; i++) cout << dst[i] << ' '; cout << '\n';
    // cout << "FRM "; for(int i=0 ; i<n ; i++) cout << from[i] << ' '; cout << '\n';
    // cout << "VIS\n";
    // for(int i=0 ; i<n ; i++) {
    //     for(int j=0 ; j<n ; j++) {
    //         if(vis[i][j]) cout << i << ' ' << j << '\n';
    //     }
    // }
    
    rdst[s] = 0;
    while(!pq.empty()) pq.pop();
    pq.push(MP(0, s));
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cdst = pq.top().first;
        pq.pop();
        
        for(auto nn: path[cur]) {
            int nxt = nn.first;
            int ndst = nn.second;
            if(vis[cur][nxt]) continue;
            if(rdst[nxt] > rdst[cur] + ndst) {
                rdst[nxt] = rdst[cur] + ndst;
                pq.push(MP(rdst[cur] + ndst, nxt));
            }
        }
    }
    
    // cout << "RDS "; for(int i=0 ; i<n ; i++) cout << rdst[i] << ' '; cout << '\n';
    
    if(rdst[d] == INF) cout << "-1\n";
    else cout << rdst[d] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    while(cin >> n >> m && n != 0 && m != 0) {
        f();
    }
}
