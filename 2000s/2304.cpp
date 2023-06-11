#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, mx, s;
queue<pii> lef, rig;
vector<pii> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int l, h;
        cin >> l >> h;
        v.push_back(pii(l, h));
        mx = max(mx, h);
    }
    sort(v.begin(), v.end());
    for(int i=0 ; i<n ; i++) {
        if(lef.empty() || v[i].second >= lef.back().second) {
            lef.push(v[i]);
        }
        if(v[i].second == mx) break;
    }
    for(int i=n-1 ; i>=0 ; i--) {
        if(rig.empty() || v[i].second >= rig.back().second) {
            rig.push(pii(v[i].first + 1, v[i].second));
        }
        if(v[i].second == mx) break;
    }
    
    s += (rig.back().first - lef.back().first) * lef.back().second;
    
    int lf = lef.front().first;
    int ls = lef.front().second;
    lef.pop();
    while(!lef.empty()) {
        s += (lef.front().first - lf) * ls;
        lf = lef.front().first;
        ls = lef.front().second;
        lef.pop();
    }
    
    lf = rig.front().first;
    ls = rig.front().second;
    rig.pop();
    while(!rig.empty()) {
        s += (lf - rig.front().first) * ls;
        lf = rig.front().first;
        ls = rig.front().second;
        rig.pop();
    }
    
    cout << s;
}
