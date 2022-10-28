#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip; 

int n, p;
int c[10001];
vector<pip> v;
int s, mnv = 99999;
int root[10001];

int _find(int x) {
    if(x == root[x]) return x;
    return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if(x == y) return;
    root[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p;
    for(int i=1 ; i<=n ; i++) {
        cin >> c[i];
        root[i] = i;
        mnv = min(mnv, c[i]);
    }
    for(int i=0 ; i<p ; i++) {
        int a, b, cs;
        cin >> a >> b >> cs;
        v.push_back(make_pair(cs*2 + c[a] + c[b], make_pair(a, b)));
    }
    sort(v.begin(), v.end());
    
    for(int i=0 ; i<p ; i++) {
        int ccost = v[i].first;
        int ca = _find(v[i].second.first);
        int cb = _find(v[i].second.second);
        
        if(ca == cb) continue;
        s += ccost;
        _union(ca, cb);
    }
    
    cout << s + mnv;
}