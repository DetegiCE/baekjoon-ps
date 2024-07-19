#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 0;
    int mx = -1;
    for(int i=0 ; i<n ; i++) {
        if(a[i] == 0) break;
        mx = max(mx, i+a[i]-1);
    }
    cout << min(mx+1, n);
}