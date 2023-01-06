#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MP(A,B) make_pair(A,B)

int n, T;
vector<int> pos[200005];
vector<int> vis[200005];
queue<ppi> q;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    cin >> n >> T;
    for(int i=0 ; i<n ; i++) {
        int x, y;
        cin >> x >> y;
        pos[y].push_back(x);
        vis[y].push_back(1e9);
    }
    for(int i=0 ; i<=T ; i++) {
        if(!pos[i].empty()) sort(pos[i].begin(), pos[i].end());
    }
    
    q.push(MP(MP(0,0),0));
    while(!q.empty()) {
        ppi qf = q.front();
        q.pop();
        
        int qfx = qf.first.first;
        int qfy = qf.first.second;
        int qfc = qf.second;
        // cout << qfx << ' ' << qfy << ' ' << qfc << '\n';
        for(int dx=-2 ; dx<=2 ; dx++) {
            for(int dy=-2 ; dy<=2 ; dy++) {
                if(dx == 0 && dy == 0) continue;
                int nxx = qfx + dx;
                int nxy = qfy + dy;
                if(nxx < 0) continue;
                if(nxy < 0) continue;
                // cout << "    " << nxx << ' ' << nxy << '\n';
                int lwb = lower_bound(pos[nxy].begin(), pos[nxy].end(), nxx) - pos[nxy].begin();
                if(lwb == pos[nxy].size()) continue;
                // cout << "dddd " << lwb << ' ' << pos[nxy][lwb] << '\n';
                if(pos[nxy][lwb] != nxx) continue;
                if(vis[nxy][lwb] <= qfc + 1) continue;
                // cout << "eeee\n";
                
                q.push(MP(MP(nxx, nxy), qfc+1));
                vis[nxy][lwb] = qfc + 1;
                if(nxy >= T) {
                    cout << qfc + 1;
                    return 0;
                }
            }
        }
    }
    cout << -1;
}
