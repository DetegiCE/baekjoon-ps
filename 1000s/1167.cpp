#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

int v;
vector<pil> p[100001];
ll mxval[100001];

ll ans = 0;

void calc(int cur, int root) {
    int cnt = 0;
    vector<ll> vals;
    for(pil nxt: p[cur]) {
        int nod = nxt.first;
        ll len = nxt.second;
        if(nod == root) continue;
        cnt++;
        calc(nod, cur);
        vals.push_back(mxval[nod] + len);
    }
    if(cnt == 0) {
        mxval[cur] = 0;
        return;
    }
    else if(cnt == 1) {
        ans = max(ans, vals[0]);
        mxval[cur] = vals[0];
        return;
    }
    else {
        sort(vals.begin(), vals.end(), greater<ll>());
        ans = max(ans, vals[0] + vals[1]);
        mxval[cur] = vals[0];
        return;
    }
}

int main()
{
    scanf("%d", &v);
    for(int i=0 ; i<v ; i++) {
        int k;
        scanf("%d", &k);
        while(1) {
            int r, q;
            scanf("%d", &r);
            if(r == -1) break;
            scanf("%d", &q);
            p[k].push_back(make_pair(r, q));
        }
    }
    calc(1, -1);
    printf("%lld\n", max(ans, mxval[1]));
}