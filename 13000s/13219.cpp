#include<cstdio>
#include<queue>
#include<utility>
#include<vector>
#include<functional>
using namespace std;

#define MP(A,B) make_pair(A,B)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> pll;

int n, ax, ay, bx, by;
ll mapp[404][404], dst[404][404];
ll ans = -1;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct cmp {
    bool operator()(const pll &a, const pll &b) {
        return a.first > b.first;
    }
};

priority_queue<pll, vector<pll>, cmp > pq;

int main()
{
    scanf("%d", &n);
    scanf("%d %d %d %d", &ay, &ax, &by, &bx);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            scanf("%lld", &mapp[i][j]);
        }
    }
    if(mapp[ax][ay] != -1) {
        pq.push(MP(mapp[ax][ay], MP(ax, ay)));
    }

    while(!pq.empty()) {
        while(!pq.empty() && dst[pq.top().second.first][pq.top().second.second]) {
            pq.pop();
        }
        if(pq.empty()) break;
        pll qf = pq.top(); pq.pop();
        int qfx = qf.second.first;
        int qfy = qf.second.second;
        if(qfx == bx && qfy == by) {
            ans = qf.first;
            break;
        }
        dst[qfx][qfy] = 1;
        for(int i=0 ; i<4 ; i++) {
            int nxx = qfx + dx[i];
            int nxy = qfy + dy[i];
            if(nxx >= 1 && nxx <= n && nxy >= 1 && nxy <= n && mapp[nxx][nxy] != -1) {
                pq.push(MP(qf.first + mapp[nxx][nxy], MP(nxx, nxy)));
            }
        }
    }

    printf("%lld", ans);
}