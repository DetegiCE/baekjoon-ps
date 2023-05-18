#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;
vector<string> v, w;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        v.clear();
        w.clear();
        mp.clear();
        int n;
        cin >> n;
        cin.ignore();
        for(int i=0 ; i<n ; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cin.ignore();
        for(int i=0 ; i<n ; i++) {
            string s;
            cin >> s;
            w.push_back(s);
        }
        cin.ignore();
        for(int i=0 ; i<n ; i++) {
            string s;
            cin >> s;
            mp[w[i]] = s;
        }
        for(int i=0 ; i<n ; i++) {
            cout << mp[v[i]] << ' ';
        }
        cout << '\n';
    }
}
