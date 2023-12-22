#include<bits/stdc++.h>
using namespace std;

int st, en;
int dst[1001];
int n, m;
vector<int> lnk[1001];
queue<int> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> st >> en;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    q.push(st);
    for(int i=1 ; i<=n ; i++) dst[i] = 1e9;
    dst[st] = 0;
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        for(int nxt: lnk[qf]) {
            if(dst[nxt] > dst[qf] + 1) {
                dst[nxt] = dst[qf] + 1;
                q.push(nxt);
            }
        }
    }
    if(dst[en] == 1e9) cout << -1;
    else cout << dst[en];
}
