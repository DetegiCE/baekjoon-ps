#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<pair<int, int> > lnk[101001];
queue<int> q;
int d[101001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0 ; i<101001 ; i++) d[i] = 1e9;
    cin >> n >> k >> m;
    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<k ; j++) {
            int t;
            cin >> t;
            lnk[n+i+1].push_back(make_pair(t, 0));
            lnk[t].push_back(make_pair(n+i+1, 1));
        }
    }

    q.push(1);
    d[1] = 1;
    while(!q.empty()) {
        int qf = q.front();
        q.pop();

        for(auto i: lnk[qf]) {
            int nxt = i.first;
            int dst = i.second;

            if(d[qf] + dst < d[nxt]) {
                d[nxt] = d[qf] + dst;
                q.push(nxt);
            }
        }
    }

    if(d[n] == 1e9) cout << -1;
    else cout << d[n];
}