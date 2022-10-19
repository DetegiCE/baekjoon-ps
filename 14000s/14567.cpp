#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, m;
int precnt[1001], lev[1001];
vector<int> lnk[1001];
queue<int> q;

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        precnt[b]++;
        lnk[a].push_back(b);
    }
    for(int i=1 ; i<=n ; i++) {
        if(precnt[i] == 0) {
            q.push(i);
            lev[i] = 1;
        }
    }
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        for(int i=0 ; i<lnk[qf].size() ; i++) {
            int nxt = lnk[qf][i];
            precnt[nxt]--;
            if(precnt[nxt] == 0) {
                lev[nxt] = lev[qf] + 1;
                q.push(nxt);
            }
        }
    }
    for(int i=1 ; i<=n ; i++) {
        cout << lev[i] << ' ';
    }
}