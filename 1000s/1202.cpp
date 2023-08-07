#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
map<ll, vector<ll>> w;
vector<ll> c;
priority_queue<ll> pq;
ll s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        ll m, v;
        cin >> m >> v;
        w[m].push_back(v);
    }
    for(int i=0 ; i<k ; i++) {
        ll v;
        cin >> v;
        c.push_back(v);
    }
    sort(c.begin(), c.end());
    for(int i=0 ; i<k ; i++) {
        if(i == 0) {
            for(int j=0 ; j<=c[0] ; j++) {
                for(auto vw: w[j]) pq.push(vw);
            }
        }
        else {
            if(c[i-1] != c[i]) {
                for(int j=c[i-1]+1 ; j<=c[i] ; j++) {
                    for(auto vw: w[j]) pq.push(vw);
                }
            }
        }
        if(!pq.empty()) {
            s += pq.top();
            pq.pop();
        }
        // cout << i << ' ' << s << '\n';
    }
    
    cout << s;
}
