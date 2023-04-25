#include<bits/stdc++.h>
using namespace std;

int n, m;
int lnk[101];
int vis[101];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0 ; i<n+m ; i++) {
        int a, b;
        cin >> a >> b;
        lnk[a] = b;
    }
    for(int i=2 ; i<=100 ; i++) vis[i] = -1;
    vis[1] = 0;
    
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        for(int i=1 ; i<=6 ; i++) {
            if(qf + i > 100) break;
            int nxt = qf+i;
            int lnx = lnk[nxt];
            if(vis[nxt] == -1 || vis[nxt] > vis[qf] + 1) {
                vis[nxt] = vis[qf] + 1;
                if(lnx != 0) {
                    if(vis[lnx] == -1 || vis[lnx] > vis[qf] + 1) {
                        vis[lnx] = vis[qf] + 1;
                        q.push(lnx);
                    }
                }
                else {
                    q.push(nxt);
                }
            }
        }
    }
    
    cout << vis[100];
}
