// https://math.stackexchange.com/questions/20529/fast-method-for-nth-squarefree-number-using-mathematica

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll k;
int mobius[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> k;
    for(int i=1 ; i<=100000 ; i++) mobius[i] = 1;
    for(int i=2 ; i*i <= 100000 ; i++) {
        if(mobius[i] == 1) {
            for(int j=i ; j<=100000 ; j+=i) mobius[j] *= -i;
            for(int j=i*i ; j<=100000 ; j+=i*i) mobius[j] = 0;
        }
    }
    
    for(int i=2 ; i<=100000 ; i++) {
        if(mobius[i] == i) mobius[i] = 1;
        else if(mobius[i] == -i) mobius[i] = -1;
        else if(mobius[i] < 0) mobius[i] = 1;
        else if(mobius[i] > 0) mobius[i] = -1;
    }
    
    ll st = 1, en = 2000000000;
    while(st < en) {
        ll mid = (st + en) / 2;
        ll val = 0;
        for(int i=1 ; i*i<=mid ; i++)
            val += mobius[i] * (mid/(i*i));
        if(val > k) en = mid - 1;
        else if(val < k) st = mid + 1;
        else en = mid;
    }
    
    cout << st;
}
