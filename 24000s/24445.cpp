#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define ALL(A) (A).begin(), (A).end()

int n, m, r;
vector<int> e[100005];
bool vis[100005];
int ord[100005], ordc;
queue<int> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> r;
    for(int i=0 ; i<m ; i++) {
        int u, v;
        cin >> u >> v;
        e[u].PB(v);
        e[v].PB(u);
    }
    for(int i=1 ; i<=n ; i++) {
        if(!e[i].empty()) sort(ALL(e[i]), greater<int>());
    }
    vis[r] = true;
    q.push(r);
    while(!q.empty()) {
        int u = q.front();
        ord[u] = ++ordc;
        q.pop();
        for(auto k: e[u]) {
            if(!vis[k]) {
                vis[k] = true;
                q.push(k);
            }
        }
    }
    for(int i=1 ; i<=n ; i++) {
        cout << ord[i] << '\n';
    }
}
