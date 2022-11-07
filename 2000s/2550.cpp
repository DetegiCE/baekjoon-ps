#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, a[10004], b[10004], s[10004], lislen[10004];
vector<int> v;
vector<int> ans;

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        int t;
        cin >> t;
        s[i] = t;
        a[t] = i;
    }
    for(int i=1 ; i<=n ; i++) {
        int t;
        cin >> t;
        b[i] = a[t];
    }
    
    v.push_back(-100000);
    for(int i=1 ; i<=n ; i++) {
        if(b[i] > v.back()) {
            v.push_back(b[i]);
            lislen[i] = v.size() - 1;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
            v[idx] = b[i];
            lislen[i] = idx;
        }
    }
    cout << v.size() - 1 << '\n';
    
    int sz = v.size() - 1;
    for(int i=n ; i>=1 ; i--) {
        if(lislen[i] == sz) {
            ans.push_back(s[b[i]]);
            sz--;
        }
        if(!sz) break;
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans) {
        cout << i << ' ';
    }
}