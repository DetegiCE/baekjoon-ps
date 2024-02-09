#include <bits/stdc++.h>
using namespace std;

void f() {
    int r, c;
    int h[102][102] = {0};
    cin >> r >> c;
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=c ; j++) {
            cin >> h[i][j];
            vector<pair<int, pair<int, int> > > vp;
            vp.push_back(make_pair(abs(h[i][j]), make_pair(0, h[i][j])));
            vp.push_back(make_pair(abs(h[i][j] - h[i][j-1]), make_pair(1, h[i][j] - h[i][j-1])));
            vp.push_back(make_pair(abs(h[i][j] - h[i-1][j]), make_pair(2, h[i][j] - h[i-1][j])));
            vp.push_back(make_pair(abs(h[i][j] - (h[i][j-1] + h[i-1][j]) / 2), make_pair(3, h[i][j] - (h[i][j-1] + h[i-1][j]) / 2)));
            vp.push_back(make_pair(abs(h[i][j] - h[i][j-1] - h[i-1][j] + h[i-1][j-1]), make_pair(4, h[i][j] - h[i][j-1] - h[i-1][j] + h[i-1][j-1])));
            sort(vp.begin(), vp.end());
            cout << vp[0].second.first << ' ' << vp[0].second.second << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        f();
    }
}
