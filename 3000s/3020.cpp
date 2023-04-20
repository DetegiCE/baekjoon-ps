#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(A) A.begin(), A.end()

int n, h;
vector<int> up, dn;

int mn, mncnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> h;
    mn = n+1;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        if(i&1) up.push_back(t);
        else dn.push_back(t);
    }
    
    sort(ALL(up));
    sort(ALL(dn));
    
    for(int i=1 ; i<=h ; i++) {
        int upc = n/2 - (lower_bound(ALL(up), i) - up.begin());
        int dnc = n/2 - (lower_bound(ALL(dn), h-i+1) - dn.begin());
        
        if(mn > upc + dnc) {
            mn = upc + dnc;
            mncnt = 1;
        }
        else if(mn == upc + dnc) mncnt++;
    }
    
    cout << mn << ' ' << mncnt;
}

