#include<bits/stdc++.h>
using namespace std;

typedef struct edge {
    int s, e, t;
} EDGE;

int n, m, w;
int dst[501];
vector<EDGE> v;

void f() {
    cin >> n >> m >> w;
    v.clear();
    
    int s, e, t;
    for(int i=0 ; i<m ; i++) {
        cin >> s >> e >> t;
        v.push_back({s, e, t});
        v.push_back({e, s, t});
    }
    for(int i=0 ; i<w ; i++) {
        cin >> s >> e >> t;
        v.push_back({s, e, -t});
    }
    
    for(int i=0 ; i<=n ; i++) dst[i] = 1e9;
    dst[1] = 0;
    for(int i=1 ; i<n ; i++) {
        for(int j=0 ; j<v.size() ; j++) {
            s = v[j].s;
            e = v[j].e;
            t = v[j].t;
            if(dst[e] > dst[s] + t) {
                dst[e] = dst[s] + t;
            }
        }
    }
    
    bool flg = false;
    for(int j=0 ; j<v.size() ; j++) {
        s = v[j].s;
        e = v[j].e;
        t = v[j].t;
        if(dst[e] > dst[s] + t) {
            flg = true;
            break;
        }
    }
    
    if(flg) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        f();
    }
}

