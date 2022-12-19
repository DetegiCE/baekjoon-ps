#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef struct query {
    int type, l, r;
} QUERY;

int n, m;
vector<QUERY> q;
vector<int> first, num;
int tree[12000000];

void update(int st, int en, int node, int idx, int dif) {
    if(idx < st || idx > en) return;
    tree[node] += dif;
    if(st == en) return;
    
    int mid = (st + en) / 2;
    update(st, mid, node * 2, idx, dif);
    update(mid + 1, en, node * 2 + 1, idx, dif);
}

int sum(int st, int en, int node, int lef, int rig) {
    if(lef > en || rig < st) return 0;
    if(lef <= st && en <= rig) return tree[node];
    int mid = (st + en) / 2;
    return sum(st, mid, node*2, lef, rig) + sum(mid+1, en, node*2+1, lef, rig);
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int qi;
        cin >> qi;
        first.push_back(qi);
        num.push_back(qi);
    }
    
    cin >> m;
    for(int i=0 ; i<m ; i++) {
        int t, a, b = 0;
        cin >> t >> a;
        if(t == 2) cin >> b;
        QUERY nq = {t, a, b};
        q.push_back(nq);
        num.push_back(a);
        if(t == 2) num.push_back(b);
    }
    num.push_back(-1000000001);
    sort(num.begin(), num.end());
    
    int sz = num.size();
    for(int i=0 ; i<n ; i++) {
        int fpos = lower_bound(num.begin(), num.end(), first[i]) - num.begin();
        update(0, sz-1, 1, fpos, 1);
    }
    for(int i=0 ; i<m ; i++) {
        if(q[i].type == 1) {
            int fpos = lower_bound(num.begin(), num.end(), q[i].l) - num.begin();
            update(0, sz-1, 1, fpos, 1);
        }
        else {
            int lpos = lower_bound(num.begin(), num.end(), q[i].l) - num.begin();
            int rpos = lower_bound(num.begin(), num.end(), q[i].r) - num.begin();
            cout << (q[i].r - q[i].l + 1) - sum(0, sz-1, 1, lpos, rpos) << '\n';
        }
    }
}