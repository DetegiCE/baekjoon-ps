#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
vector<int> t;
int ans = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        string t;
        cin >> t;
        v.push_back(t);
    }
    for(int i=0 ; i<n ; i++) {
        t.push_back(i);
    }
    do {
        string s = v[t[0]];
        for(int i=1 ; i<n ; i++) {
            int slen = s.length();
            int tlen = v[t[i]].length();
            for(int j=min(slen, tlen) ; j>=0 ; j--) {
                string stemp = s.substr(slen-j, j);
                string ttemp = v[t[i]].substr(0, j);
                if(stemp == ttemp) {
                    for(int k=j ; k<tlen ; k++) {
                        s += v[t[i]][k];
                    }
                    break;
                }
            }
        }
        ans = min(ans, (int)s.length());
    } while(next_permutation(t.begin(), t.end()));
    cout << ans;
}
