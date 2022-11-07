#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n, r;
int root[200002];
map<int,int> path[200002];
vector<pip> v;

int _find(int x) {
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
    for(int i=0 ; i<n ; i++) root[i] = i, path[i].clear();
    v.clear();
    
    int tsum = 0;
    for(int i=0 ; i<r ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tsum += c;
        if(a > b) {
            int t = a;
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
    for(int i=0 ; i<n ; i++) {
        for(auto k: path[i]) {
            v.push_back(MP(k.second, MP(i, k.first)));
        }
    }
    sort(v.begin(), v.end());
    
    int sum = 0;
    for(auto i: v) {
        int n1 = _find(i.second.first);
        int n2 = _find(i.second.second);
        int nw = i.first;
        
        if(n1 != n2) {
            _union(n1, n2);
            sum += nw;
        }
    }
    cout << tsum - sum << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        sol();
    }
}
