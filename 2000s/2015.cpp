#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

ll n, k, a[200004], c[200004], ans;
map<int, ll> mp;

int main()
{
    INP;
    
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        c[i] = c[i-1] + a[i];
    }
    
    for(int i=1 ; i<=n ; i++) {
        if(c[i] == k) ans++;
        ans += mp[c[i]-k];
        mp[c[i]]++;
    }
    
    cout << ans;
}