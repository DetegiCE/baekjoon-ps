#include<cstdio>
#include<vector>
using namespace std;

struct Party {
    int cnt;
    vector<int> member;
};

int n, m, tc, truth[51];
vector<Party> vp;

int root[51], _rank[51];

int _find(int x) {
    if(root[x] == x) return x;
    else return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if(x == y) return;

    if(_rank[x] < _rank[y]) root[x] = y;
    else {
        root[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        root[i] = i;
    }
    scanf("%d", &tc);
    for(int i=0 ; i<tc ; i++) {
        scanf("%d", &truth[i]);
    }
    for(int i=1 ; i<tc ; i++) {
        _union(truth[i-1], truth[i]);
    }
    int t, t2, t3;
    for(int i=0 ; i<m ; i++) {
        Party tpt;
        scanf("%d %d", &tpt.cnt, &t2);
        tpt.member.push_back(t2);
        for(int j=1 ; j<tpt.cnt ; j++) {
            scanf("%d", &t3);
            tpt.member.push_back(t3);
            _union(t2, t3);
        }
        vp.push_back(tpt);
    }
    if(tc == 0) {
        printf("%d", m);
        return 0;
    }

    // for(int i=0 ; i<=n ; i++) printf("%d ", _find(root[i])); puts("");

    int cnt = 0;
    for(int i=0 ; i<m ; i++) {
        if(_find(vp[i].member[0]) != _find(truth[0])) cnt++;
    }
    printf("%d", cnt);
}