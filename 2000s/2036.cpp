#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans, one;
vector<ll> pos, neg;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll t;
        cin >> t;
        if(t == 1) one++;
        else if(t > 0) pos.push_back(t);
        else neg.push_back(t);
    }
    sort(pos.begin(), pos.end(), greater<ll>());
    sort(neg.begin(), neg.end());
    for(int i=0 ; i<pos.size() ; i+=2) {
        if(i == pos.size()-1) {
            ans += pos[i];
        }
        else ans += pos[i] * pos[i+1];
    }
    for(int i=0 ; i<neg.size() ; i+=2) {
        if(i == neg.size()-1) {
            ans += neg[i];
        }
        else ans += neg[i] * neg[i+1];
    }
    cout << ans + one;
}
