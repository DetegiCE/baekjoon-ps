#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int dst(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    vector<pii> v;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(pii(x, y));
    }
    if(k == 1) {
        int mn = 300000;
        for(int i=0 ; i<n ; i++) {
            int mx = 0;
            for(int j=0 ; j<n ; j++) {
                int d = dst(v[i], v[j]);
                mx = max(mx, d);
            }
            mn = min(mn, mx);
        }
        cout << mn;
    }
    if(k == 2) {
        int mn = 300000;
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                int mx = 0;
                for(int l=0 ; l<n ; l++) {
                    int d1 = dst(v[i], v[l]);
                    int d2 = dst(v[j], v[l]);
                    int d = min(d1, d2);
                    mx = max(mx, d);
                }
                mn = min(mn, mx);
            }
        }
        cout << mn;
    }
    if(k == 3) {
        int mn = 300000;
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                for(int l=j+1 ; l<n ; l++) {
                    int mx = 0;
                    for(int m=0 ; m<n ; m++) {
                        int d1 = dst(v[i], v[m]);
                        int d2 = dst(v[j], v[m]);
                        int d3 = dst(v[l], v[m]);
                        int d = min(min(d1, d2), d3);
                        mx = max(mx, d);
                    }
                    mn = min(mn, mx);
                }
            }
        }
        cout << mn;
    }
}
