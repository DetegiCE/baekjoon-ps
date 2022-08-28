#include<bits/stdc++.h>
using namespace std;

int root, del, par[51];
vector<int> sib[51];
int ans;

void dfs(int pos) {
    int scnt = 0;
    for(int i=0 ; i<sib[pos].size() ; i++) {
        int nxt = sib[pos][i];
        if(nxt == del) continue;
        scnt++;
        dfs(nxt);
    }
    if(scnt == 0) {
        ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> par[i];
        if(par[i] == -1) root = i;
        sib[par[i]].push_back(i);
    }
    cin >> del;

    if(root == del) {
        cout << 0;
        return 0;
    }
    dfs(root);
    cout << ans;
    return 0;
}