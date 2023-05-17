#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, k;
queue<pii> q;
int s, sz;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=k ; j++) {
            int t;
            cin >> t;
            q.push(pii(i, t));
        }
    }
    while(!q.empty()) {
        int qff = q.front().first;
        int qfs = q.front().second;
        q.pop();
        if(q.empty()) {
            cout << qff << ' ' << qfs;
            return 0;
        }
        qfs--;
        
        while(qfs--) {
            q.push(q.front());
            q.pop();
        }
    }
    
}
