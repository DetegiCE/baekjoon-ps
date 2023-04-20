#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pdd = pair<double,double>;
using pii = pair<int,int>;
using t3p = tuple<double,int,int>;
#define F first
#define S second

int n;
vector<pdd> v;

int root[101];
priority_queue<t3p> pq;
double tot;

int _find(int x) {
    if(root[x] == x) return x;
    return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    
    if(x == y) return;
    root[x] = y;
}

double dst(int x, int y) {
    return sqrt((v[x].F-v[y].F)*(v[x].F-v[y].F)+(v[x].S-v[y].S)*(v[x].S-v[y].S));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        double p, q;
        cin >> p >> q;
        v.push_back(pdd(p, q));
        root[i] = i;
    }
    
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            pq.push(t3p(-dst(i, j), i, j));
        }
    } 
    
    while(!pq.empty()) {
        t3p pt = pq.top();
        pq.pop();
        
        double cdst = -get<0>(pt);
        int cx = get<1>(pt);
        int cy = get<2>(pt);
        
        cx = _find(cx);
        cy = _find(cy);
        if(cx == cy) continue;
        
        tot += cdst;
        _union(cx, cy);
    }
    
    cout << tot;
}
