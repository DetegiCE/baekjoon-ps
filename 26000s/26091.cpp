#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int lef = 0;
    int rig = n-1;
    int cnt = 0;
    while(lef < rig) {
        if(a[lef] + a[rig] >= m) {
            cnt++;
            lef++;
            rig--;
        }
        else if(a[lef] + a[rig] < m) {
            lef++;
        }
    }
    cout << cnt;
    
}
