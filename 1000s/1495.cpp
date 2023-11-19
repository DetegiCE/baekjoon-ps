#include<bits/stdc++.h>
using namespace std;

int n, s, m;
int vol[1002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> m;
    vol[s] = 1;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        vector<int> a;
        for(int j=0 ; j<=m ; j++) {
            if(vol[j] && j-t >= 0) a.push_back(j-t);
            if(vol[j] && j+t <= m) a.push_back(j+t);
        }
        for(int j=0 ; j<=m ; j++) vol[j] = 0;
        for(int k: a) {
            vol[k] = 1;
        }
        if(a.size() == 0) {
            cout << -1;
            return 0;
        }
    }
    for(int i=m ; i>=0 ; i--) {
        if(vol[i]) {
            cout << i;
            return 0;
        }
    }
}
