#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll k;
int mobius[300005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> k;
    for(int i=1 ; i<=300000 ; i++) mobius[i] = 1;
    for(int i=2 ; i*i <= 300000 ; i++) {
        if(mobius[i] == 1) {
            for(int j=i ; j<=300000 ; j+=i) mobius[j] *= -i;
            for(int j=i*i ; j<=300000 ; j+=i*i) mobius[j] = 0;
        }
    }
    
    for(int i=2 ; i<=300000 ; i++) {
        if(mobius[i] == i) mobius[i] = 1;
        else if(mobius[i] == -i) mobius[i] = -1;
        else if(mobius[i] < 0) mobius[i] = 1;
        else if(mobius[i] > 0) mobius[i] = -1;
    }
    
    ll st = 1, en = 90000000000;
    while(st < en) {
        ll mid = (st + en) / 2;
        // cout << mid << '\n';
        ll val = 0;
        for(ll i=1 ; i*i<=mid ; i++)
            val += mobius[i] * (mid/(i*i));
        val = mid - val;
        if(val > k) en = mid - 1;
        else if(val < k) st = mid + 1;
        else en = mid;
    }
    
    cout << st;
}
