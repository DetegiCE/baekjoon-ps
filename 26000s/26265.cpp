#include<bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
vector<pss> vp;

bool compare(pss a, pss b) {
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        string a, b;
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    sort(vp.begin(), vp.end(), compare);
    for(int i=0 ; i<n ; i++) {
        cout << vp[i].first << ' ' << vp[i].second << '\n';
    }
}