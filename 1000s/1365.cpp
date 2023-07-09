#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, a = 0;
    cin >> n;
    
    vector<int> v;
    v.push_back(-1);
    for(int i=0 ; i<n ; i++) {
        int x;
        cin >> x;
        if(v.back() < x) {
            v.push_back(x);
            a++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    
    cout << n - a;
}
