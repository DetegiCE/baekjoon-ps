#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

int main()
{
    INP;
    
    ll r, c, m=1;
    ll MOD = 998244353;
    cin >> r >> c;
    for(ll i=r+1 ; i<=r*c ; i++) {
        m *= i;
        m %= MOD;
    }
    cout << m;
}