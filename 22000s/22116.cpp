#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

ll n, r;
ll mapp[1005][1005];
ll root[1000005];
map<ll,ll> path[1000005];
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

int coord(int y, int x) {
    return y*n + x;
}

void sol() {
    ll st, en;
    for(int i=0 ; i<n*n ; i++) root[i] = i, path[i].clear();
    v.clear();
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> mapp[i][j];
        }
    }
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(i < n-1) path[coord(i, j)].insert({coord(i+1, j), abs(mapp[i][j]-mapp[i+1][j])});
            if(j < n-1) path[coord(i, j)].insert({coord(i, j+1), abs(mapp[i][j]-mapp[i][j+1])});
        }
    }
    
    
    st = 0;
    en = coord(n-1, n-1);
    
    for(int i=0 ; i<n*n ; i++) {
        for(auto k: path[i]) {
            v.push_back(MP(k.second, MP(i, k.first)));
        }
    }
    sort(v.begin(), v.end());
    
    ll mx = 0;
    for(auto i: v) {
        ll n1 = _find(i.second.first);
        ll n2 = _find(i.second.second);
        ll nw = i.first;
        
        if(n1 != n2) {
            _union(n1, n2);
            mx = max(mx, nw);
        }
        
        st = _find(st);
        en = _find(en);
        if(st == en) {
            cout << mx << '\n';
            return;
        }
    }
    cout << "0";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    sol();
}
