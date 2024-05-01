#include<bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> v;
        for(int i=0 ; i<n ; i++) {
            long long w;
            cin >> w;
            v.push_back(w);
        }
        sort(v.begin(), v.end());
        long long s = 0, m = 1;
        for(int i=0 ; i<n ; i++) {
            s += v[i];
            m *= v[i];
            if(s < m) break;
        }
        if(s > m) cout << "SUMA\n";
        else if(s < m) cout << "ILOCZYN\n";
        else cout << "=\n";
    }
}
