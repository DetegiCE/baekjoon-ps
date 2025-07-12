#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string mp[1001];
int root[1001][1001];
bool vis[1001][1001];
set<int> st;

int chk(int y, int x, int r) {
    // cout << "chk " << y << ' ' << x << '\n';
    if(vis[y][x]) {
        if(root[y][x] == 0) {
            cnt++;
            return cnt;
        }
        return root[y][x];
    }
    vis[y][x] = true;
    if(mp[y][x] == 'U') {
        return root[y][x] = chk(y-1, x, r);
    }
    else if(mp[y][x] == 'D') {
        return root[y][x] = chk(y+1, x, r);
    }
    else if(mp[y][x] == 'L') {
        return root[y][x] = chk(y, x-1, r);
    }
    else {
        return root[y][x] = chk(y, x+1, r);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        cin >> mp[i];
        for(int j=0 ; j<m ; j++) {
            vis[i][j] = false;
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(!vis[i][j]){
                chk(i, j, cnt);
            }
        }
    }
    // for(int i=0 ; i<n ; i++) {
    //     for(int j=0 ; j<m ; j++) {
    //         cout << root[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            st.insert(root[i][j]);
        }
    }
    cout << st.size();
}