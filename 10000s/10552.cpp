#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int nxt[100001];
int hpy[100001];
int hte[100001];
bool vis[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> p;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        if(nxt[b] == 0) nxt[b] = a;
        hpy[a]++;
        hte[b]++;
    }

    int cnt = 0;
    bool flg = false;
    while(true) {
        if(vis[p]) {
            cout << -1;
            return 0;
        }
        vis[p] = true;
        if(hte[p]) {
            p = nxt[p];
        }
        else {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
}