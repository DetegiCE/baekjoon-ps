#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
using ll = long long;
using pll = pair<ll, ll>;

int n;
ll ans;
vector<pll> orig, tmp;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll x, y;
        cin >> x >> y;
        orig.push_back(pll(x, y));
    }
    for(int i=0 ; i<n ; i++) {
        ll tcnt = 0;
        map<pll, int> mp;
        tmp = orig;
        swap(tmp[0], tmp[i]);
        for(int j=1 ; j<n ; j++) {
            ll x = tmp[j].F - tmp[0].F;
            ll y = tmp[j].S - tmp[0].S;
            ll g = gcd(x, y);
            x /= g;
            y /= g;
            mp[pll(x, y)]++;
        }
        for(auto k: mp) {
            ll cf = k.first.first;
            ll cs = k.first.second;
            if(mp.find(pll(-cs, cf)) != mp.end()) {
                tcnt += k.second * (mp[pll(-cs, cf)]);
            }
        }
        ans += tcnt;
    }
    
    cout << ans;
}
