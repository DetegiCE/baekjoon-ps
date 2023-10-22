#include<bits/stdc++.h>
using namespace std;

int n;
int pop[10004];
vector<int> lnk[10004];
int vis[10004];
int dp[10004][2];

void tree(int cur) {
    if(vis[cur]) return;
    
    vis[cur] = 1;
    dp[cur][0] = 0;
    dp[cur][1] = pop[cur];
    
    for(int nxt: lnk[cur]) {
        if(vis[nxt]) continue;
        
        tree(nxt);
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> pop[i];
    }
    for(int i=0 ; i<n-1 ; i++) {
        int u, v;
        cin >> u >> v;
        lnk[u].push_back(v);
        lnk[v].push_back(u);
    }
    
    tree(1);
    
    cout << max(dp[1][0], dp[1][1]);
}
