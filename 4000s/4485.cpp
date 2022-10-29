#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n;
int mapp[127][127];
int price[16000];
map<int,int> path[16000];

int dijk(int st, int en) {
    for(int i=0 ; i<n*n ; i++) price[i] = INF;
    priority_queue<pii> pq;
    price[st] = 0;
    pq.push(MP(0, st));
    while(!pq.empty()) {
        int cdst = (-1) * pq.top().first;
        int cpos = pq.top().second;
        pq.pop();
        
        for(auto i: path[cpos]) {
            int nxt = i.first;
            int ndst = i.second;
            
            if(ndst + cdst < price[nxt]) {
                price[nxt] = ndst + cdst;
                pq.push(MP(-ndst-cdst, nxt));
            }
        }
    }
    return price[en];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 0;
    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                cin >> mapp[i][j];
                int cur = i * n + j;
                path[cur].clear();
            }
        }
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(i == n-1 && j == n-1) break;
                int cur = i * n + j;
                if(i == n-1) {
                    path[cur].insert({cur+1, mapp[i][j+1]});
                    path[cur+1].insert({cur, mapp[i][j]});
                }
                else if(j == n-1) {
                    path[cur].insert({cur+n, mapp[i+1][j]});
                    path[cur+n].insert({cur, mapp[i][j]});
                }
                else {
                    path[cur].insert({cur+1, mapp[i][j+1]});
                    path[cur+1].insert({cur, mapp[i][j]});
                    path[cur].insert({cur+n, mapp[i+1][j]});
                    path[cur+n].insert({cur, mapp[i][j]});
                }
            }
        }
        t++;
        cout << "Problem " << t << ": ";
        cout << dijk(0, n*n-1) + mapp[0][0] << '\n';
    }
}