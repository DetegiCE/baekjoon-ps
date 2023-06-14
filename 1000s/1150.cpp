#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using pip = pair<ll,pii>;

int n, k, f;
vector<int> v;
ll ans;
int visL[100005], visR[100005];
int cst[100005];
set<pii> s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    for(int i=1 ; i<n ; i++) {
        cst[i] = v[i] - v[i-1];
        visL[i] = i-1;
        visR[i] = i+1;
        // cout << i << ' ' << v[i] << ' ' << v[i-1] << '\n';
        s.insert(pii(cst[i], i));
    }
    
    while(k--) {
        pii cur = *s.begin();
        s.erase(cur);
        
        ll dst = cur.first;
        ll pos = cur.second;
        
        // cout << dst << ' ' << pos << '\n';
        
        ans += dst;
        
        int vll = visL[pos];
        int vrr = visR[pos];
        // cout << vll << ' ' << vrr << '\n';
        visL[pos] = visL[vll];
        visR[pos] = visR[vrr];
        
        if(vll != 0) visL[visR[vrr]] = pos;
        else visL[visR[vrr]] = 0;
        if(vrr != n) visR[visL[vll]] = pos;
        else visR[visL[vll]] = n;
        
        // cout << "visL ";
        // for(int i=1 ; i<n ; i++) cout << visL[i] << ' '; cout << '\n';
        // cout << "visR ";
        // for(int i=1 ; i<n ; i++) cout << visR[i] << ' '; cout << '\n';
        // cout << "cst ";
        // for(int i=1 ; i<n ; i++) cout << cst[i] << ' '; cout << '\n';
        
        cst[pos] = cst[vll] + cst[vrr] - dst;
        if(vll > 0 && vrr < n) {
            // cout << "IN " << vll << " " << vrr << " " << cst[pos] << '\n';
            s.insert(pii(cst[pos], pos));
        }
        
        s.erase(pii(cst[vll], vll));
        s.erase(pii(cst[vrr], vrr));
    }
    
    cout << ans;
}
