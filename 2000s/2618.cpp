#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, w;
int dp[1002][1002];
vector<pii> v;

inline int dist(int ax, int ay, int bx, int by) {
    return abs(ax-bx) + abs(ay-by);
}

int f(int p1, int p2)  {
    if(p1 == w || p2 == w) return 0;
    
    if(dp[p1][p2] != -1) return dp[p1][p2];
    
    int nxt = max(p1, p2) + 1;
    
    int d1, d2;
    if(p1 == 0) d1 = dist(1, 1, v[nxt].first, v[nxt].second);
    else d1 = dist(v[p1].first, v[p1].second, v[nxt].first, v[nxt].second);
    if(p2 == 0) d2 = dist(n, n, v[nxt].first, v[nxt].second);
    else d2 = dist(v[p2].first, v[p2].second, v[nxt].first, v[nxt].second);
    
    return dp[p1][p2] = min(f(p1, nxt) + d2, f(nxt, p2) + d1);
}

void track(int p1, int p2) {
    if(p1 == w || p2 == w) return;
    
    int nxt = max(p1, p2) + 1;
    
    int d1, d2;
    if(p1 == 0) d1 = dist(1, 1, v[nxt].first, v[nxt].second);
    else d1 = dist(v[p1].first, v[p1].second, v[nxt].first, v[nxt].second);
    if(p2 == 0) d2 = dist(n, n, v[nxt].first, v[nxt].second);
    else d2 = dist(v[p2].first, v[p2].second, v[nxt].first, v[nxt].second);
    
    if(dp[nxt][p2] + d1 > dp[p1][nxt] + d2) {
        cout << "2\n";
        track(p1, nxt);
    }
    else {
        cout << "1\n";
        track(nxt, p2);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> w;
    v.push_back(pii(0,0));
    for(int i=0 ; i<w ; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(pii(a, b));
    }
    memset(dp, -1, sizeof(dp));
    
    cout << f(0, 0) << '\n';
    track(0, 0);
}
