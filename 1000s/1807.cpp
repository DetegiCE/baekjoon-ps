#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll k;

ll dig(ll v) {
    ll comp = 10;
    ll compd = 1;
    ll sum = 0;
    while(1) {
        if(v >= comp) {
            sum += (comp/10) * 9 * (compd + 1);
            comp *= 10;
            compd ++;
        }
        else {
            sum += (v-(comp/10)+1) * (compd + 1);
            break;
        }
    }
    return sum;
}

ll fours(ll v) {
    return v/4;
}

void f() {
    ll lef = 1, rig = k;
    ll mid, cnts;
    while(lef < rig) {
        mid = (lef + rig) / 2;
        cnts = dig(mid) - fours(mid);
        if(cnts < k) {
            lef = mid + 1;
        }
        else if(cnts > k) {
            rig = mid;
        }
        else {
            lef = mid;
            break;
        }
    }
    cnts = dig(lef) - fours(lef);
    ll cntd = dig(lef-1) - fours(lef-1) + 1;
    string ansv = to_string(lef);
    if(lef % 4 == 1 || lef % 4 == 3) ansv += "2";
    if(lef % 4 == 2) ansv += "0";
    cout << ansv[k-cntd] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    while(1) {
        cin >> k;
        if(!k) break;
        f();
    }
}
