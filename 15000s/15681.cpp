#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

typedef struct node {
    int tot;
    vector<int> child;
} NODE;

int n, r, q;
vector<NODE> tree;

vector<int> path[100002];
bool vis[100002];

void makeTree(int cur) {
    vis[cur] = true;
    for(auto i: path[cur]) {
        if(!vis[i]) {
            tree[cur].child.PB(i);
            tree[cur].tot++;
            makeTree(i);
            tree[cur].tot += tree[i].tot;
        }
    }
}

int main()
{
    INP;
    
    cin >> n >> r >> q;
    tree.resize(n+1);
    for(int i=0 ; i<n-1 ; i++) {
        int u, v;
        cin >> u >> v;
        path[u].PB(v);
        path[v].PB(u);
    }
    makeTree(r);
    for(int i=0 ; i<q ; i++) {
        int u;
        cin >> u;
        cout << (tree[u].tot + 1) << '\n';
    }
}