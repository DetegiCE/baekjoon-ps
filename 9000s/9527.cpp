#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
    if(n <= 0) return 0;
    ll s = 0;
    for(ll i=54 ; i>=0 ; i--) {
        if((1L << i) & n) {
            s += i * (1L << (i-1));
            s += (n - (1L << i) + 1);
            s += f(n - (1L << i));
            return s;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;
    cout << f(b) - f(a-1);
}