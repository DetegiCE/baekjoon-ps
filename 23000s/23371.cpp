#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, s, k;
    int cnt[1001] = {0};
    int mx = 0;
    cin >> n >> s >> k;
    for(int i=0 ; i<k ; i++) {
        int t;
        cin >> t;
        cnt[(t-1)/s]++;
        mx = max(mx, cnt[(t-1)/s]);
    }
    for(int i=mx ; i>=1 ; i--) {
        for(int j=0 ; j<n ; j++) {
            if(cnt[j] < i) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
    for(int i=0 ; i<n ; i++) cout << '-';
}
