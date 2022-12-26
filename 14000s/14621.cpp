#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MP(A,B) make_pair(A,B)

int n, m, s;
char gndr[1003];
int root[1003];
priority_queue<pip> pq;

int _find(int pos) {
    if(root[pos] == pos) return pos;
    return root[pos] = _find(root[pos]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if(x == y) return;
    root[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        cin >> gndr[i];
        root[i] = i;
    }
    for(int i=0 ; i<m ; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if(gndr[u] == gndr[v]) continue;
        pq.push(MP(-d,MP(u,v)));
    }
    while(!pq.empty()) {
        pip pf = pq.top();
        pq.pop();
        
        int pfd = -pf.first;
        int pfx = pf.second.first;
        int pfy = pf.second.second;
        
        pfx = _find(pfx);
        pfy = _find(pfy);
        if(pfx == pfy) continue;
        _union(pfx, pfy);
        s += pfd;
    }
    
    root[1] = _find(1);
    for(int i=2 ; i<=n ; i++) {
        if(_find(root[i]) != root[1]) {
            cout << -1;
            return 0;
        }
    }
    cout << s;
}
