#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int incnt[200005];
bool h[200005];
pii lnk[200005];
int n, cnt;
queue<int> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        incnt[a]++;
        incnt[b]++;
        lnk[i+1].first = a;
        lnk[i+1].second = b;
    }
    for(int i=1 ; i<=n ; i++) {
        if(incnt[i] < 2) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int qf = q.front();
        q.pop();
        
        if(h[qf]) continue;
        
        h[qf] = true;
        cnt++;
        incnt[lnk[qf].first]--;
        incnt[lnk[qf].second]--;
        
        if(incnt[lnk[qf].first] <= 1) q.push(lnk[qf].first);
        if(incnt[lnk[qf].second] <= 1) q.push(lnk[qf].second);
    }
    
    cout << n - cnt << '\n';
    for(int i=1 ; i<=n ; i++) {
        if(!h[i]) cout << i << ' ';
    }
}
