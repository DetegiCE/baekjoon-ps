#include<bits/stdc++.h>
using namespace std;
#define INF 9876543210
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<ll,ll> pii;

ll n, m;
ll price[300003];
map<ll,ll> path[300003];

void dijk(ll st) {
    for(int i=1 ; i<=n ; i++) price[i] = INF;
    priority_queue<pii> pq;
    price[st] = 0;
    pq.push(MP(0, st));
    while(!pq.empty()) {
        ll cdst = (-1) * pq.top().first;
        ll cpos = pq.top().second;
        pq.pop();
        
        for(auto i: path[cpos]) {
            ll nxt = i.first;
            ll ndst = i.second;
            
            if(ndst + cdst < price[nxt]) {
                price[nxt] = ndst + cdst;
                pq.push(MP(-ndst-cdst, nxt));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll k, x;
    cin >> n >> m >> k >> x;
    for(int i=0 ; i<m ; i++) {
        ll a, b;
        cin >> a >> b;
        path[a].insert({b, 1});
    }
    dijk(x);
    bool flg = false;
    for(ll i=2 ; i<=n ; i++) {
        if(price[i] == k) {
            cout << i << '\n';
            flg = true;
        }
    }
    if(!flg) cout << -1;
}