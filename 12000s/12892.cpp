#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
typedef long long ll;

typedef struct present {
    ll p;
    ll v;
} PRS;

ll n, d, mx;
vector<PRS> v;

bool comp(PRS a, PRS b) {
    return a.p < b.p;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> d;
    for(int i=0 ; i<n ; i++) {
        PRS np;
        cin >> np.p >> np.v;
        v.PB(np);
    }
    
    sort(v.begin(), v.end(), comp);
    
    int st = 0;
    ll s = 0;
    for(int en=0 ; en<n ; en++) {
        s += v[en].v;
        if(v[en].p - v[st].p < d) {
            mx = max(mx, s);
        }
        while(v[en].p - v[st].p >= d) {
            s -= v[st].v;
            st++;
        }
        mx = max(mx, s);
    }
    cout << mx;
}
