#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define MOD 1000000007
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
vector<int> path[20002];
int dst[20002];
queue<int> q;

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) dst[i] = INF;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        path[a].PB(b);
        path[b].PB(a);
    }
    q.push(1);
    dst[1] = 0;
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        for(auto i: path[qf]) {
            if(dst[i] == INF) {
                dst[i] = dst[qf] + 1;
                q.push(i);
            }
        }
    }
    
    int mxdst = -1;
    for(int i=1 ; i<=n ; i++) {
        if(dst[i] != INF) mxdst = max(mxdst, dst[i]);
    }
    
    int mxcnt = 0;
    for(int i=1 ; i<=n ; i++) {
        if(dst[i] == mxdst) {
            cout << i << ' ' << mxdst << ' ';
            break;
        }
    }
    for(int i=1 ; i<=n ; i++) {
        if(dst[i] == mxdst) mxcnt++;
    }
    cout << mxcnt;
    
}