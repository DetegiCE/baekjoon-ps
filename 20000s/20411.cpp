#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll m, s, x1, x2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> s >> x1 >> x2;
    for(ll a=0 ; a<m ; a++) {
        for(ll c=0 ; c<m && (a*(s-x1)-(x1-x2))%m==0 ; c++) {
            if((x1+x2)%m == (a*(s+x1)+c*2)%m) {
                cout << a << ' ' << c;
                return 0;
            }
        }
    }   
}
