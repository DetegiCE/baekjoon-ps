#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
    ll n, m;
    cin >> n >> m;
    if(n >= m) cout << 0;
    else {
        ll ans = 1;
        for(ll i=n ; i>=2 ; i--) {
            ans *= i;
            ans %= m;
        }
        cout << ans;
    }
}
