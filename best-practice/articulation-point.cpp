#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vt[10001];
int ord[10001];
bool cut[10001];
int v, e;
int d;

int dfs(int v, bool root) {
    d++;
    ord[v] = d;

    int ret = ord[v];
    int child = 0;
    for(int i=0 ; i<vt[v].size() ; i++) {
        int nxt = vt[v][i];
        if(ord[nxt] == 0) {
            child++;
            int dnxt = dfs(nxt, false);
            if(!root && dnxt >= ord[v]) {
                cut[v] = true;
            }
            ret = min(ret, dnxt);
        }
        else {
            ret = min(ret, ord[nxt]);
        }
    }
    if(root && child > 1) {
        cut[v] = true;
    }
    return ret;
}

int main()
{
    scanf("%d %d", &v, &e);
    for(int i=0 ; i<e ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(int i=1 ; i<=v ; i++) {
        if(ord[i] == 0) {
            dfs(i, true);
        }
    }

    int cnt = 0;
    for(int i=1 ; i<=v ; i++) {
        if(cut[i]) cnt++;
    }

    printf("%d\n", cnt);
    for(int i=1 ; i<=v ; i++) {
        if(cut[i]) printf("%d ", i);
    }
}