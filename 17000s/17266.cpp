#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
deque<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    v.push_front(-v[0]);
    v.push_back(2*n-v[m]);
    
    for(int i=0 ; i<m+1 ; i++) {
        ans = max(ans, v[i+1]-v[i]);
    }
    cout << (ans+1)/2;
}
