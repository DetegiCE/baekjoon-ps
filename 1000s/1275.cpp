#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll val[100000];
ll tree[400000];

ll init(int st, int en, int node) {
    if(st == en) {
        tree[node] = val[st];
        return tree[node];
    }
    
    int mid = (st+en)/2;
    return tree[node] = init(st, mid, node*2) + init(mid+1, en, node*2+1);
}

ll getsum(int st, int en, int lef, int rig, int node) {
    if(en < lef || rig < st) return 0;
    if(lef <= st && en <= rig) return tree[node];
    int mid = (st+en)/2;
    return getsum(st, mid, lef, rig, node*2) + getsum(mid+1, en, lef, rig, node*2+1);
}

void update(int st, int en, int idx, ll dif, int node) {
    if(idx < st || en < idx) return;
    
    int mid = (st + en) / 2;
    tree[node] += dif;
    if(st == en) return;
    
    update(st, mid, idx, dif, node*2);
    update(mid+1, en, idx, dif, node*2+1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int q;
    cin >> n >> q;
    
    for(int i=0 ; i<n ; i++) {
        cin >> val[i];
    }
    
    init(0, n-1, 1);
    while(q--) {
        int x, y, a;
        ll b;
        cin >> x >> y >> a >> b;
        if(y < x) swap(x, y);
        cout << getsum(0, n-1, x-1, y-1, 1) << '\n';
        update(0, n-1, a-1, b-val[a-1], 1);
        val[a-1] = b;
    }
}
