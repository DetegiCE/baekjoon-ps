#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool chk[200001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vector<pii> v1, v2, v3, v4;
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int x, a, b, c, d;
        cin >> x >> a >> b >> c >> d;
        v1.push_back(make_pair(-a, x));
        v2.push_back(make_pair(-b, x));
        v3.push_back(make_pair(-c, x));
        v4.push_back(make_pair(-d, x));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    cout << v1[0].second << ' ';
    chk[v1[0].second] = true;
    for(int i=0 ; i<n ; i++) {
        if(!chk[v2[i].second]) {
            cout << v2[i].second << ' ';
            chk[v2[i].second] = true;
            break;
        }
    }
    for(int i=0 ; i<n ; i++) {
        if(!chk[v3[i].second]) {
            cout << v3[i].second << ' ';
            chk[v3[i].second] = true;
            break;
        }
    }
    for(int i=0 ; i<n ; i++) {
        if(!chk[v4[i].second]) {
            cout << v4[i].second << ' ';
            chk[v4[i].second] = true;
            break;
        }
    }
}
