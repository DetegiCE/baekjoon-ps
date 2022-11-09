#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

int n;
ll a[20002];
bool vis[20002];
vector<ll> ans;

ll gcd(ll a, ll b) {
    return b?gcd(b, a%b):a;
}

ll cycle(int p) {
    vis[p] = true;
    if(vis[a[p]]) return 1;
    return cycle(a[p]) + 1;
}

void sol() {
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        vis[i] = false;
    }
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) {
            ans.push_back(cycle(i));
        }
    }
    if(ans.size() == 1) {
        cout << ans[0];
    }
    else {
        ll l = ans[0] * ans[1] / gcd(ans[0], ans[1]);
        for(int i=2 ; i<ans.size() ; i++) {
            ll tg = gcd(l, ans[i]);
            l = l * ans[i] / tg;
        }
        cout << l;
    }
    return; 
}

int main()
{
    INP;
    
    sol();
}