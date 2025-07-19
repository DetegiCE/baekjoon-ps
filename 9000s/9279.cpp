#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, c;
vector<pii> v[1001];
int rt[1001];

int g(int pos, int par) {
    int ncnt = 0;
    for(pii nxt: v[pos]) {
        if(rt[nxt.first] == -1) {
            rt[nxt.first] = pos;
            ncnt++;
        }
    }
    int myv = -1;
    for(pii nxt: v[par]) {
        if(nxt.first == pos) myv = nxt.second;
    }
    if(ncnt == 0) {
        // cout << pos << ' ' << par << ':' << myv << '\n';
        return myv;
    }
    int tot = 0;
    for(pii nxt: v[pos]) {
        if(rt[nxt.first] == pos)
            tot += g(nxt.first, pos);
    }
    if(myv == -1) return tot;
    // cout << pos << ' ' << par << ':' << tot << ' ' << myv << '\n';
    return min(tot, myv);
}

void f() {
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    for(int i=1 ; i<=n ; i++) {
        v[i].clear();
        rt[i] = -1;
    }
    for(int i=0 ; i<n-1 ; i++) {
        int st, en, va;
        cin >> st >> en >> va;
        v[st].push_back({en, va});
        v[en].push_back({st, va});
    }
    rt[c] = 0;
    cout << g(c, 0) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> n >> c) {
        f();
    }
}