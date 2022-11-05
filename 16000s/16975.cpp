//fenwick
#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

ll n;
ll a[100002];
ll b[100002];
ll f[100002];

void update(ll idx, ll val) {
    while(idx <= n) {
        f[idx] += val;
        idx = idx + (idx & -idx);
    }
}

ll sum(int idx) {
    ll res = 0;
    while(idx > 0) {
        res += f[idx];
        idx = idx - (idx & -idx);
    }
    return res;
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    b[1] = a[1];
    for(int i=2 ; i<=n ; i++) b[i] = a[i] - a[i-1];
    for(int i=1 ; i<=n ; i++) update(i, b[i]);
    
    int q;
    cin >> q;
    for(int i=0 ; i<q ; i++) {
        int comm;
        cin >> comm;
        if(comm == 1) {
            ll a, b, c;
            cin >> a >> b >> c;
            update(a, c);
            update(b+1, -c);
        }
        else {
            ll a;
            cin >> a;
            cout << sum(a) << '\n';
        }
    }
}
