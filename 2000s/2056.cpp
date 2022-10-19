#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, m;
int precnt[10001];
int elap[10001], telap[10001];
vector<int> rlnk[10001];
vector<int> lnk[10001];
queue<int> q;

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        int tcnt;
        cin >> elap[i] >> tcnt;
        for(int j=0 ; j<tcnt ; j++) {
            int a;
            cin >> a;
            precnt[a]++;
            lnk[i].push_back(a);
            rlnk[a].push_back(i);
        }
    }
    for(int i=1 ; i<=n ; i++) {
        if(precnt[i] == 0) {
            q.push(i);
            telap[i] = elap[i];
        }
    }
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        for(int i=0 ; i<lnk[qf].size() ; i++) {
            int nxt = lnk[qf][i];
            precnt[nxt]--;
            if(precnt[nxt] == 0) {
                int mx = 0;
                for(int j=0 ; j<rlnk[nxt].size() ; j++) {
                    mx = max(mx, telap[rlnk[nxt][j]]);
                }
                telap[nxt] = mx + elap[nxt];
                q.push(nxt);
            }
        }
    }
    int mx = 0;
    for(int i=1 ; i<=n ; i++) {
        mx = max(mx, telap[i]);
    }
    cout << mx;
}