#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

ll n, r;
ll root[100005];
map<ll,ll> path[100005];
vector<pip> v;

ll _find(int x) {
    if(root[x] == x) return x;
    return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    
    if(x == y) return;
    root[y] = x;
}

void sol() {
    cin >> r;
    ll st, en;
    for(ll i=1 ; i<=n ; i++) root[i] = i, path[i].clear();
    v.clear();
    
    for(ll i=0 ; i<r ; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        c = -c;
        if(a > b) {
            ll t = a;
            a = b;
            b = t;
        }
        auto it = path[a].find(b);
        if(it != path[a].end()) {
            it->second = min(it->second, c);
        }
        else {
            path[a].insert({b, c});
        }
    }
    cin >> st >> en;
    for(ll i=1 ; i<=n ; i++) {
        for(auto k: path[i]) {
            v.push_back(MP(k.second, MP(i, k.first)));
        }
    }
    sort(v.begin(), v.end());
    
    ll mn = 2000000000;
    for(auto i: v) {
        ll n1 = _find(i.second.first);
        ll n2 = _find(i.second.second);
        ll nw = -i.first;
        
        if(n1 != n2) {
            _union(n1, n2);
            mn = min(mn, nw);
        }
        
        st = _find(st);
        en = _find(en);
        if(st == en) {
            cout << mn << '\n';
            return;
        }
    }
    cout << "0";
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    sol();
}
