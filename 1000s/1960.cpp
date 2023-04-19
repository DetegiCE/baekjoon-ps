#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, rs, cs;
vector<int> r;
vector<pii> c;
int ans[502][502];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        r.push_back(t);
        rs += t;
    }
    
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        c.push_back(pii(t, i));
        cs += t;
    }
    
    if(rs != cs) {
        cout << -1;
        return 0;
    }
    
    for(int i=0 ; i<n ; i++) {
        int t = r[i];
        sort(c.begin(), c.end(), greater<pii>());
        for(int j=0 ; j<n ; j++) {
            if(!t) break;
            if(c[j].first > 0) {
                t--;
                c[j].first--;
                ans[i][c[j].second] = 1;
            }
        }
        if(t > 0) {
            cout << -1;
            return 0;
        }
    }
    
    cout << "1\n";
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
