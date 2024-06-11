#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int j, n;
        cin >> j >> n;
        vector<int> a;
        for(int i=0 ; i<n ; i++) {
            int r, c;
            cin >> r >> c;
            a.push_back(r * c);
        }
        sort(a.begin(), a.end());
        int cnt = 0;
        int tot = 0;
        
        for(int i=n-1 ; i>=0 ; i--) {
            tot += a[i];
            cnt++;
            if(tot >= j) break;
        }
        cout << cnt << '\n';
    }
}
