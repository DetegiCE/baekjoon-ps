#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;

vector<int> lnk[250005];
int n, q;
int par[250005], s[250005], use[250005], spar[250005];
ll cnt[250005];
bool vis[250005];

int _find(int x) {
    if(spar[x] == x) return x;
    return spar[x] = _find(spar[x]);
}

void tree(int cur) {
    vis[cur] = true;
    for(int k: lnk[cur]) {
        if(vis[k]) continue;
        tree(k);
        par[k] = cur;
    }
}

void f(int th) {
    ll ans = 0;
    int k;
    cin >> k;
    for(int i=0 ; i<k ; i++) {
        cin >> s[i];
        use[s[i]] = th;
        cnt[s[i]] = 1;
        spar[s[i]] = s[i];
    }
    for(int i=0 ; i<k ; i++) {
        if(use[s[i]] == th && use[par[s[i]]] == th) {
            int a = _find(s[i]);
            int b = _find(par[s[i]]);
            
            cnt[b] += cnt[a];
            spar[a] = b;
        }
    }
    for(int i=0 ; i<k ; i++) {
        if(spar[s[i]] == s[i]) {
            ans += (cnt[s[i]]*(cnt[s[i]]-1)/2);
        }
    }
    cout << ans << '\n';
}

int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n-1 ; i++) {
        int a, b;
        cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    tree(1);
    cin >> q;
    while(q--) {
        f(q+1);
    }
}
