#include<bits/stdc++.h>
using namespace std;

int n, s, sum;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i=0 ; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(auto it=v.begin() ; it!=v.end() ; it++) {
        int idxup = upper_bound(it+1, v.end(), s-(*it)) - (it+1);
        sum += idxup;
    }
    cout << sum;
}
