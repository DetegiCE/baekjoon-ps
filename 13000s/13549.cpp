#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

#define mp(A,B) (make_pair(A,B))

typedef pair<int,int> pii;

bool vis[200001];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    pq.push(mp(0, n));
    vis[n] = true;
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(cur.second == k) {
            printf("%d\n", cur.first);
            return 0;
        }
        if(cur.second * 2 <= 200000 && !vis[cur.second*2]) {
            pq.push(mp(cur.first, cur.second*2));
            vis[cur.second*2] = true;
        }
        if(cur.second - 1 >= 0 && !vis[cur.second - 1]) {
            pq.push(mp(cur.first + 1, cur.second - 1));
            vis[cur.second - 1] = true;
        }
        if(cur.second + 1 < 200001 && !vis[cur.second + 1]) {
            pq.push(mp(cur.first + 1, cur.second + 1));
            vis[cur.second + 1] = true;
        }
    }
}