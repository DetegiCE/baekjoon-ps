#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(int i=1 ; i<n ; i++) {
        if(v[i-1] == v[i]) {
            cout << v[i];
            break;
        }
    }
}
