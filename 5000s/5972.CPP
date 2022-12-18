#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)

int n, m;
int dist[50005];
vector<pii> path[50005];
priority_queue<pii> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) dist[i] = 50000005;
    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].PB(MP(b,c));
        path[b].PB(MP(a,c));
    }
    
    dist[1] = 0;
    pq.push(MP(0,1));
    while(!pq.empty()) {
        pii pt = pq.top();
        pq.pop();
        int ptd = -pt.first;
        int ptp = pt.second;
        if(dist[ptp] < ptd) continue;
        for(auto i: path[ptp]) {
            if(dist[i.first] > ptd + i.second) {
                int nxd = ptd + i.second;
                dist[i.first] = nxd;
                pq.push(MP(-nxd, i.first));
            }
        }
    }
    
    cout << dist[n];
}