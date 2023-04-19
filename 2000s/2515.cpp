#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, s;
vector<int> hs;
vector<pii> e;
int dp[300005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;
    for(int i=0 ; i<n ; i++) {
        int h, c;
        cin >> h >> c;
        e.push_back(pii(h, c));
        hs.push_back(h);
    } 
    sort(e.begin(), e.end());
    sort(hs.begin(), hs.end());
    dp[0] = e[0].second;
    for(int i=1 ; i<n ; i++) {
        auto bnd = upper_bound(hs.begin(), hs.end(), e[i].first - s);
        if(bnd == hs.begin()) {
            dp[i] = max(dp[i-1], e[i].second);
        }
        else {
            dp[i] = max(dp[i-1], dp[bnd-hs.begin()-1] + e[i].second);
        }
    }
    
    // for(int i=0 ; i<n ; i++) {
    //     cout << e[i].first << ' ' << e[i].second << ' ' << dp[i] << '\n';
    // }
    cout << dp[n-1];
}
