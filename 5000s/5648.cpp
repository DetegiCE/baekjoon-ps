#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(A) A.begin(), A.end()

int n;
vector<ll> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll t, s = 0;
        cin >> t;
        while(t) {
            s *= 10;
            s += t % 10;
            t /= 10;
        }
        v.push_back(s);
    }
    sort(ALL(v));
    for(auto i: v) {
        cout << i << '\n';
    }
}
