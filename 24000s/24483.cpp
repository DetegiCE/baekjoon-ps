#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, r;
vector<int> lnk[100005];
ll dep[100005];
ll tim[100005];
ll tv;

void dfs(int cur, int depth) {
    tim[cur] = ++tv;
    dep[cur] = depth;
    for(int nxt: lnk[cur]) {
        if(dep[nxt] == -1) {
            dfs(nxt, depth+1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> r;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++) {
        dep[i] = -1;
        sort(lnk[i].begin(), lnk[i].end());
    }
    dfs(r, 0);
    
    ll sum = 0;
    for(int i=1 ; i<=n ; i++) {
        // cout << tim[i] << ' ' << dep[i] << '\n';
        sum += tim[i] * dep[i];
    }
    cout << sum;
}
