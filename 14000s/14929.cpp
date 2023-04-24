#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a[100005], c[100005], s;

int main()
{
    cin >> n;
    for(ll i=0 ; i<n ; i++) cin >> a[i];
    c[0] = a[0];
    for(ll i=1 ; i<n ; i++) c[i] = c[i-1] + a[i];
    for(ll i=0 ; i<n ; i++) {
        s += a[i] * (c[n-1] - c[i]);
    }
    cout << s;
}
