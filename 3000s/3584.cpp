#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> pii;

typedef struct node {
    int par;
    vector<int> sib;    
} NODE;

NODE nodes[10001];
int lev[10001];
int root;

bool vis[10001];
int dist[10001];

int minlev;
int minpos;

void getLevels(int node, int level) {
    lev[node] = level;
    for(int i=0 ; i<nodes[node].sib.size() ; i++) {
        int nxt = nodes[node].sib[i];
        getLevels(nxt, level+1);
    }
}

void bfs(int st, int en) {
    vis[st] = true;
    dist[st] = 0;
    queue<pii> q;
    q.push(make_pair(st,0));
    while(!q.empty()) {
        int qf = q.front().first;
        q.pop();

        if(nodes[qf].par != -1 && !vis[nodes[qf].par]) {
            vis[nodes[qf].par] = true;
            dist[nodes[qf].par] = dist[qf] + 1;
            q.push(make_pair(nodes[qf].par, dist[qf]+1));
        }
        for(int i=0 ; i<nodes[qf].sib.size() ; i++) {
            int nxt = nodes[qf].sib[i];
            if(!vis[nxt]) {
                vis[nxt] = true;
                dist[nxt] = dist[qf] + 1;
                if(nxt == en) return;
                q.push(make_pair(nxt, dist[nxt]));
            }
        }
    }
}

void _search(int en, int st) {
    int cur = en;
    minlev = lev[en];
    minpos = en;
    for(int i=dist[en]-1 ; i>=0 ; i--) {
        // printf("i:%d, cur:%d, dist[ncp]:%d\n", i, cur, dist[nodes[cur].par]);
        if(nodes[cur].par == -1) {
            minlev = 0;
            minpos = root;
            return;
        }
        if(dist[nodes[cur].par] == i) {
            minlev--;
            minpos = nodes[cur].par;
            cur = nodes[cur].par;
        }
        else return;
    }
}

void sol() {
    int n;
    scanf("%d", &n);
    minlev = 99999;
    minpos = -1;
    for(int i=1 ; i<=n ; i++) {
        nodes[i].sib.clear();
        nodes[i].par = -1;
        lev[i] = -1;
        dist[i] = 99999;
        vis[i] = false;
    }
    for(int i=0 ; i<n-1 ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a].sib.push_back(b);
        nodes[b].par = a;
    }
    for(int i=1 ; i<=n ; i++) {
        if(nodes[i].par == -1) {
            root = i;
            break;
        }
    }
    getLevels(root, 0);

    int st, en;
    scanf("%d %d", &st, &en);
    dist[st] = 0;
    bfs(st, en);
    // for(int i=1 ; i<=n ; i++) printf("%d : %d %d\n", i, dist[i], lev[i]);
    _search(en, st);

    printf("%d\n", minpos);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        sol();
    }
}