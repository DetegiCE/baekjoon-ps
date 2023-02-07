#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f() {
    ll n, q;
    ll rows[1002] = {0,}, cols[1002] = {0,};
    cin >> n >> q;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            ll t;
            cin >> t;
            rows[i] += t;
            cols[j] += t;
        }
    }
    while(q--) {
        ll r1, c1, r2, c2, v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        r1--;
        r2--;
        c1--;
        c2--;
        for(ll i=r1 ; i<=r2 ; i++)
            rows[i] += v * (c2 - c1 + 1);
        for(ll i=c1 ; i<=c2 ; i++)
            cols[i] += v * (r2 - r1 + 1);
    }
    for(int i=0 ; i<n ; i++) cout << rows[i] << ' '; cout << '\n';
    for(int i=0 ; i<n ; i++) cout << cols[i] << ' '; cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    ll t;
    cin >> t;
    while(t--) {
        f();
    }
}
