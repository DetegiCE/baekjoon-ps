#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<ll,ll> pll;

ll n, m, dirt[100005];
priority_queue<pll> open, cls;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        cin >> dirt[i];
    }
    for(int i=0 ; i<m ; i++) {
        ll a, b, k;
        cin >> a >> b >> k;
        open.push(MP(-a, k));
        cls.push(MP(-b, k));
    }
    ll cur = 0;
    for(int i=1 ; i<=n ; i++) {
        while(!open.empty() && open.top().first == -i) {
            cur += open.top().second;
            open.pop();
        }
        cout << dirt[i] + cur << ' ';
        while(!cls.empty() && cls.top().first == -i) {
            cur -= cls.top().second;
            cls.pop();
        }
    }
}