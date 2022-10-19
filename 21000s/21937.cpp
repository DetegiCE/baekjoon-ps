#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n, m, cnt;
vector<int> lnk[100001];
bool vis[100001];
queue<int> q;

int main()
{
    INP;
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        lnk[b].push_back(a);
    }
    int x;
    
    cin >> x;
    q.push(x);
    vis[x] = true;
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        for(int i=0 ; i<lnk[qf].size() ; i++) {
            int nxt = lnk[qf][i];
            if(!vis[nxt]) {
                cnt++;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << cnt;
}