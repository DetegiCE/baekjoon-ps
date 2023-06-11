#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int v, e;
vector<int> graph[100005];
vector<pii> ans;
int vis[100005], cnt;

int dfs(int cur, int par) {
    cnt++;
    vis[cur] = cnt;
    
    int ret = vis[cur];
    for(int nxt: graph[cur]) {
        if(nxt == par) continue;
        
        if(!vis[nxt]) {
            int fst = dfs(nxt, cur);
            if(fst > vis[cur]) {
                ans.push_back(pii(min(cur,nxt), max(cur,nxt)));
            }
            ret = min(ret, fst);
        }
        else {
            ret = min(ret, vis[nxt]);
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> v >> e;
    for(int i=0 ; i<e ; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(pii a: ans) {
        cout << a.first << ' ' << a.second << '\n';
    }
}
