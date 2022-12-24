#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll s, k;
    cin >> s >> k;
    
    ll a = s / k;
    ll ac = s % k;
    ll ans = 1;
    for(int i=0 ; i<k-ac ; i++) ans *= a;
    for(int i=k-ac ; i<k ; i++) ans *= (a+1);
    cout << ans;
}
