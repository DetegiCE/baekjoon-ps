#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<int> p;
queue<int> q;
int vis[30001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    if(m == 0) {
        cout << 0;
        return 0;
    }
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    for(int i=0 ; i<n ; i++) {
        q.push(p[i]);
        vis[p[i]+15000] = 1;
    }
    if(vis[m+15000]) {
        cout << 1;
        return 0;
    }
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        int qfv = vis[qf+15000];

        for(int i: p) {
            int nxt = i + qf;
            if(nxt > 11500 || nxt < -11500) continue;
            if(nxt == m) {
                cout << qfv + 1;
                return 0;
            }
            if(!vis[nxt+15000] && vis[nxt+15000] < qfv + 1) {
                if(!vis[nxt+15000]) q.push(nxt);
                vis[nxt+15000] = qfv + 1;
            }
        }
    }

    cout << -1;
}