#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define ALL(A) (A).begin(), (A).end()
typedef long long ll;

int n;
vector<ll> v;
ll wg[1001], cnt[1001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll t;
        cin >> t;
        v.PB(t);
    }
    wg[0] = v[0];
    cnt[0] = 1;
    for(int i=1 ; i<n ; i++) {
        for(int j=i-1 ; j>=0 ; j--) {
            if(wg[j] >= v[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                wg[i] = wg[j] + v[i];
            }
        }
        if(wg[i] == 0) {
            wg[i] = v[i];
            cnt[i] = 1;
        }
    }
    
    ll mx = 0;
    for(int i=0 ; i<n ; i++) {
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}
