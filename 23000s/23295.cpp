#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
typedef long long ll;

int on[100005], off[100005], pps[100005];
int n, t, stt;
ll mx;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> t;
    for(int i=0 ; i<n ; i++) {
        int k;
        cin >> k;
        for(int j=0 ; j<k ; j++) {
            int s, e;
            cin >> s >> e;
            on[s]++;
            off[e]++;
        }
    }
    
    ll sc = 0, pp = 0;
    for(int i=0 ; i<t ; i++) {
        pp -= off[i];
        pp += on[i];
        pps[i] = pp;
        sc += pp;
    }
    mx = max(mx, sc);
    for(int i=t ; i<=100000 ; i++) {
        sc -= pps[i-t];
        pp -= off[i];
        pp += on[i];
        pps[i] = pp;
        sc += pp;
        if(sc > mx) {
            mx = sc;
            stt = i-t+1;
        }
    }
    cout << stt << ' ' << stt + t;
}
