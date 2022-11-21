#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

typedef struct node {
    ll po;
    ll npo;
    vector<int> child;
} NODE;

int n;
vector<NODE> tree;
ll a[200002];

void dfs(int cur) {
    if(tree[cur].child.size() == 0) {
        return;
    }
    
    ll mxsum = 0;
    for(auto c: tree[cur].child) {
        dfs(c);
        mxsum += max(tree[c].po, tree[c].npo);
    }
    tree[cur].npo = mxsum;
    for(auto c: tree[cur].child) {
        tree[cur].po = max(tree[cur].po, tree[c].npo + a[c] * a[cur] + mxsum - max(tree[c].po, tree[c].npo));
    }
}

int main()
{
    INP;
    
    cin >> n;
    tree.resize(n+1);
    for(int i=2 ; i<=n ; i++) {
        int c;
        cin >> c;
        tree[c].child.PB(i);
    }
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    dfs(1);
    cout << max(tree[1].po, tree[1].npo);
}