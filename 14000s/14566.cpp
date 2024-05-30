#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int dst = 32800001;
    for(int i=0 ; i<n-1 ; i++) {
        dst = min(dst, v[i+1] - v[i]);
    }
    
    cout << dst << ' ';
    int cnt = 0;
    for(int i=0 ; i<n-1 ; i++) {
        if(v[i+1] - v[i] == dst) cnt++;
    }
    cout << cnt;
}
