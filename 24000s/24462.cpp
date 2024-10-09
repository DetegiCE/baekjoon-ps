#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> pip;

ll n, d;
vector<pip> v;
ll mxi1, mxi2, mxv;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> d;
    
    for(int i=0 ; i<n ; i++) {
        ll t, k;
        cin >> t >> k;
        v.push_back({i, {t, k}});
    }
    
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            ll in = v[i].first;
            ll jn = v[j].first;
            ll it = v[i].second.first;
            ll ik = v[i].second.second;
            ll jt = v[j].second.first;
            ll jk = v[j].second.second;
            if(it == 0) {
                ll a1 = d / ik + 1;
                if(jt == 0) {
                    ll a2 = d / jk + 1;
                    ll a3 = d / lcm(ik, jk) + 1;
                    ll at = a1 + a2 - a3;
                    if(mxv < at) {
                        mxv = at;
                        mxi1 = in;
                        mxi2 = jn;
                    }
                }
                else {
                    ll a2 = d / jk - (jt / jk) + 1;
                    ll a3 = d / lcm(ik, jk) - (jt - 1) / lcm(ik, jk);
                    ll at = a1 + a2 - a3;
                    if(mxv < at) {
                        mxv = at;
                        mxi1 = in;
                        mxi2 = jn;
                    }
                }
            }
            else { // it != 0
                if(jt == 0) {
                    ll a1 = d / ik - (it / ik) + 1;
                    ll a2 = d / jk + 1;
                    ll a3 = d / lcm(ik, jk) - (it - 1) / lcm(ik, jk);
                    ll at = a1 + a2 - a3;
                    if(mxv < at) {
                        mxv = at;
                        mxi1 = in;
                        mxi2 = jn;
                    }
                }
                else {
                    ll a1 = d / ik - (it / ik) + 1;
                    ll a2 = d / jk - (jt / jk) + 1;
                    ll a3 = 0;
                    if(it > jt) {
                        a3 = d / lcm(ik, jk) - (it - 1) / lcm(ik, jk);
                    }
                    else {
                        a3 = d / lcm(ik, jk) - (jt - 1) / lcm(ik, jk);
                    }
                    ll at = a1 + a2 - a3;
                    if(mxv < at) {
                        mxv = at;
                        mxi1 = in;
                        mxi2 = jn;
                    }
                }
            }
        }
    }
    
    cout << mxi1+1 << ' ' << mxi2+1 << '\n' << mxv;
}
