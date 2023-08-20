#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
ll a[200005], s[200005], d[200005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
    }
    for(int i=1 ; i<=n ; i++) {
        s[i] = s[i-1] + a[i];
    }
    d[1] = s[1] > 0 ? s[1] : 0;
    for(int i=2 ; i<=n ; i++) {
        d[i] = max(d[i-1], s[i] - d[i-1]);
    }
    cout << d[n];
}
