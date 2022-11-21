#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define INF 9999999999999
typedef long long ll;
typedef pair<ll,ll> pii;

ll n, m, k;
vector<pii> path[100003];
ll mndst[100003];
ll dst[100003];
priority_queue<pii> pq;

void dijkstra() {
    while(!pq.empty()) {
        pii qf = pq.top();
        pq.pop();
        
        ll qfn = qf.second;
        ll qfd = -qf.first;
        if(dst[qfn] < qfd) continue;
        for(auto i: path[qfn]) {
            if(dst[i.first] > qfd + i.second) {
                ll ndst = qfd + i.second;
                dst[i.first] = ndst;
                pq.push(MP(-ndst, i.first));
            }
        }
    }
}

int main() 
{
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i=1 ; i<=n ; i++) mndst[i] = INF;
    for(ll i=0 ; i<m ; i++) {
        ll u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        path[v].PB(MP(u, c));
    }
    for(ll i=1 ; i<=n ; i++) dst[i] = INF;
    for(ll i=0 ; i<k ; i++) {
        ll t;
        scanf("%lld", &t);
        pq.push(MP(0, t));
        dst[t] = 0;
    }
    dijkstra();
    
    ll mxd = -1;
    ll mxi = 0;
    for(ll i=1 ; i<=n ; i++) {
        if(dst[i] > mxd) {
            mxd = dst[i];
            mxi = i;
        }
    }
    printf("%lld\n%lld", mxi, mxd);
}