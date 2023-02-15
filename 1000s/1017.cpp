#include <bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)

int n;
vector<int> ans, m[51];
int v[51], m1[51], m2[51];
bool prime[2003], vis[51];

bool dfs(int pos) {
    if(vis[pos]) return false;
    vis[pos] = true;
    for(auto k: m[pos]) {
        if(m2[k] == -1 || dfs(m2[k])) {
            m1[pos] = k;
            m2[k] = pos;
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=2 ; i<=2000 ; i++) prime[i] = true;
    for(int i=2 ; i*i<=2000 ; i++) {
        if(prime[i]) {
            for(int j=i*i ; j<=2000 ; j+=i) {
                prime[j] = false;
            }
        }
    }
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> v[i];
    }
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(i != j && prime[v[i] + v[j]]) {
                m[i].PB(j);
            }
        }
    }
    
    for(auto k: m[0]) {
        for(int i=0 ; i<n ; i++) m1[i] = m2[i] = -1;
        
        int f = 1;
        m2[k] = 0;
        m1[0] = k;
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) vis[j] = false;
            vis[0] = true;
            if(dfs(i)) f++;
        }
        if(f == n) ans.PB(v[k]);
    }
    
    if(ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(auto k: ans) {
            cout << k << ' ';
        }
    }
}
