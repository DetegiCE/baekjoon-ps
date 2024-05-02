#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> v, w;
    int t, s;
    cin >> t;
    for(int i=0 ; i<t ; i++) {
        cin >> s;
        v.push_back(s);
    }
    for(int i=0 ; i<t ; i++) {
        cin >> s;
        w.push_back(s);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    int cnt = 0;
    for(int i=0 ; i<t ; i++) {
        if(v[i] <= w[i]) cnt++;
    }
    if(cnt == t) cout << "DA";
    else cout << "NE";
}
