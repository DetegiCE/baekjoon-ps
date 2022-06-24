#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long int

typedef struct edge {
    int st;
    int en;
    ll va;

    edge(int st, int en, ll va):
        st(st), en(en), va(va) {}
} EDGE;

bool operator<(EDGE a, EDGE b) {
    return a.va < b.va;
}

vector<EDGE> ed;

int v, e;
bool vis[100001];
int root[100001];

int _find(int x) {
    if(root[x] == 0) return root[x] = x;
    if(root[x] == x) return x;
    else return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if(x == y) return;
    root[y] = x;
}

int main()
{
    ll tsum = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i=0 ; i<e ; i++) {
        int st, en;
        ll va;
        cin >> st >> en >> va;
        tsum += va;
        ed.push_back(edge(st, en, va));
    }
    sort(ed.begin(), ed.end());

    ll sum = 0;
    for(int i=0 ; i<e ; i++) {
        if(_find(ed[i].st) == _find(ed[i].en)) continue;
        else {
            vis[ed[i].st] = true;
            vis[ed[i].en] = true;
            _union(ed[i].st, ed[i].en);
            sum += ed[i].va;
        }
    }
    int of = _find(1);
    for(int i=2 ; i<=v ; i++) {
        if(_find(i) != of) {
            puts("-1");
            return 0;
        }
    }

    cout << tsum - sum;
}