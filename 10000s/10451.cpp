#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n;
int a[1002];
bool vis[1002];

bool cycle(int p) {
    vis[p] = true;
    if(vis[a[p]]) return true;
    return cycle(a[p]);
}

void sol() {
    int ans = 0;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        vis[i] = false;
    }
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) {
            if(cycle(i)) ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    INP;
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}