#include<bits/stdc++.h>
using namespace std;

int n, ans;
int team[100005];
bool vis[100005], chk[100005];

void dfs(int pos) {
    vis[pos] = true;
    if(!vis[team[pos]]) dfs(team[pos]);
    else if(!chk[team[pos]]) {
        for(int i=team[pos] ; i!=pos ; i=team[i]) {
            ans++;
        }
        ans++;
    }
    chk[pos] = true;
}

void sol() {
    ans = 0;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> team[i];
        vis[i] = false;
        chk[i] = false;
    }
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    cout << n - ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}
