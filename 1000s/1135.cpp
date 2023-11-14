#include<bits/stdc++.h>
using namespace std;

int n;
int par[51];
vector<int> ch[51];

int f(int c) {
    int s = ch[c].size();
    int mx = 0;
    vector<int> v;
    for(int i: ch[c]) {
        v.push_back(f(i));
    }
    sort(v.begin(), v.end());
    int cnt = ch[c].size();
    for(int i: v) {
        mx = max(mx, i+cnt);
        cnt--;
    }
    s = max(s, mx);
    // cout << c << ' ' << s << '\n';
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> par[i];
        if(i) {
            ch[par[i]].push_back(i);
        }
    }
    cout << f(0);
}
