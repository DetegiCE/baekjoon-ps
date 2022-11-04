#include<bits/stdc++.h>
using namespace std;

int n, l;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    int cnt = 0;
    auto it = v.begin();
    while(it < v.end()) {
        it = lower_bound(v.begin(), v.end(), *it+l);
        cnt++;
    }
    cout << cnt;
}