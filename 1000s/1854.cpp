#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> pii;

int n, m, k;
vector<pii> path[1001];
priority_queue<int> dst[1001];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].PB(MP(b,c));
    }
    dst[1].push(0);
    pq.push(MP(0,1));
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cdst = pq.top().first;
        pq.pop();
        
        for(auto nn: path[cur]) {
            int nxt = nn.first;
            int ndst = nn.second;
            if(dst[nxt].size() < k || dst[nxt].top() > cdst + ndst) {
                if(dst[nxt].size() == k) dst[nxt].pop();
                dst[nxt].push(cdst + ndst);
                pq.push(MP(cdst + ndst, nxt));
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        if(dst[i].size() < k) cout << "-1\n";
        else cout << dst[i].top() << '\n';
    }
}
