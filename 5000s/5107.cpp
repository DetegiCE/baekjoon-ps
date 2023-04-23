#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> lnk[21];
bool vis[21];
map<string,int> mp;
int tcnt, rcnt;

void dfs(int st, int cur) {
    vis[cur] = true;
    for(auto nxt: lnk[cur]) {
        if(!vis[nxt]) {
            dfs(st, nxt);
            return;
        }
    }
}

void f() {
    for(int i=0 ; i<21 ; i++) lnk[i].clear();
    for(int i=0 ; i<21 ; i++) vis[i] = false;
    mp.clear();
    tcnt = 0;
    rcnt = 0;
    
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        string a, b;
        cin >> a >> b;
        int anum, bnum;
        if(mp.find(a) == mp.end()) {
            mp[a] = ++tcnt;
            anum = tcnt;
        }
        else anum = mp[a];
        if(mp.find(b) == mp.end()) {
            mp[b] = ++tcnt;
            bnum = tcnt;
        }
        else bnum = mp[b];
        
        lnk[anum].push_back(bnum);
    }
    
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) {
            dfs(i, i);
            rcnt++;
        }
    }
}

int main()
{
    for(int i=1 ;; i++) {
        cin >> n;
        if(n == 0) break;
        cout << i << ' ';
        f();
        cout << rcnt << '\n';
    }
}
