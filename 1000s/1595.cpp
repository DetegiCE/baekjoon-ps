#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)

vector<pii> path[10004];
bool vis[10004];
int mxdst;

void dfs(int pos, int dst) {
    mxdst = max(mxdst, dst);
    for(auto k: path[pos]) {
        if(!vis[k.first]) {
            vis[k.first] = true;
            dfs(k.first, dst + k.second);
        }
    }
}

int main()
{
    int a, b, c;
    while(cin >> a >> b >> c) {
        path[a].PB(MP(b,c));
        path[b].PB(MP(a,c));
    }
    for(int i=1 ; i<=10000 ; i++) {
        for(int j=1 ; j<=10000 ; j++) vis[j] = false;
        vis[i] = true;
        dfs(i, 0);
    }
    cout << mxdst;
}
