#include<bits/stdc++.h>
using namespace std;
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
typedef pair<int,int> pii;

int n;
vector<pii> v;
vector<int> lis, pos, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        v.PB(MP(a,b));
    }
    sort(v.begin(), v.end());
    lis.PB(v[0].second);
    pos.PB(1);
    for(int i=1 ; i<n ; i++) {
        int end = *lis.rbegin();
        if(v[i].second > end) {
            lis.PB(v[i].second);
            pos.PB(lis.size());
        }
        else {
            int lpos = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
            lis[lpos] = v[i].second;
            pos.PB(lpos+1);
        }
    }
    cout << n - lis.size() << '\n';
    int sz = lis.size();
    for(int i=n-1 ; i>=0 ; i--) {
        if(pos[i] == sz) {
            pos[i] = -1;
            sz--;
        }
    }
    for(int i=0 ; i<n ; i++) {
        if(pos[i] != -1) {
            ans.PB(v[i].first);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto k: ans) {
        cout << k << '\n';
    }
}