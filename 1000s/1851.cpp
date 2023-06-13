#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

ll n, ans;
bool vis[100005];
vector<pii> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll p;
        cin >> p;
        v.push_back(pii(p, i));
    }
    sort(v.begin(), v.end());
    
    for(int i=0 ; i<n ; i++) {
        if(vis[i]) continue;
        
        ll cnt = 0;
        ll cur = i;
        while(!vis[cur]) {
            vis[cur] = true;
            ans += v[cur].first;
            cnt++;
            cur = v[cur].second;
        }
        ans += min(v[0].first*(cnt+1)+v[i].first, v[i].first*(cnt-2));
    }
    cout << ans;
}
