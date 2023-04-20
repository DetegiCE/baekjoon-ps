#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(A) A.begin(), A.end()

int n;
vector<ll> v;
ll mn;
ll va[3];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    mn = 1e11;
    for(int i=0 ; i<n ; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }
    sort(ALL(v));
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            int pos = lower_bound(ALL(v), -v[i]-v[j]) - v.begin();
            for(int k=max(0, pos-3) ; k<=min(n-1, pos+3) ; k++) {
                if(k == i || k == j) continue;
                ll cs = v[i] + v[j] + v[k];
                if(abs(mn) > abs(cs)) {
                    // cout << i << ' ' << j << ' ' << k << ' ';
                    // cout << v[i] << ' ' << v[j] << ' ' << v[k] << ' ' << cs << '\n';
                    mn = abs(cs);
                    va[0] = v[i];
                    va[1] = v[j];
                    va[2] = v[k];
                }
            }
        }
    }
    
    sort(va, va+3);
    for(int i=0 ; i<3 ; i++) {
        cout << va[i] << ' ';
    }
}
