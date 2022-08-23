#include<bits/stdc++.h>
using namespace std;

#define INF 2e9

typedef long long ll;
typedef pair<ll,int> pli;

typedef struct edge {
    int to;
    ll cost;
    ll limit;
    
    edge(int to, ll cost, ll limit):
    to(to), cost(cost), limit(limit) {};
} EDGE;

vector<EDGE> path[100001];
ll n, m, k;
ll dist[100001];

struct compare {
    bool operator()(pli a, pli b) {
        return a.first > b.first;
    }
};

priority_queue<pli, vector<pli>, compare> pq;

ll calcCost(ll c, ll p, ll t) {
    return c * (p - t) * (p - t);
}

ll dijk(ll p) {
    // printf("dijk(%lld)\n", p);
    dist[1] = 0;
    for(int i=2 ; i<=n ; i++) dist[i] = INF;
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        ll curdist = pq.top().first;
        int curidx = pq.top().second;
        pq.pop();

        for(int i=0 ; i<path[curidx].size() ; i++) {
            int nxtidx = path[curidx][i].to;
            ll nxtdist;
            if(p <= path[curidx][i].limit) nxtdist = 0;
            else nxtdist = calcCost(path[curidx][i].cost, p, path[curidx][i].limit);

            if(curdist + nxtdist < dist[nxtidx]) {
                dist[nxtidx] = curdist + nxtdist;
                pq.push(make_pair(dist[nxtidx], nxtidx));
            }
        }
    }
    return dist[n];
}

int main()
{
    ll left = INF;
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i=0 ; i<m ; i++) {
        int a, b;
        ll c, t;
        scanf("%d %d %lld %lld", &a, &b, &c, &t);
        path[a].push_back(edge(b, c, t));
        path[b].push_back(edge(a, c, t));
        left = min(left, t);
    }

    ll right = 2e5;
    ll pmax = left;
    while(left <= right) {
        // printf("L %lld, R %lld\n", left, right);
        ll mid = (left + right) / 2L;
        ll cur = dijk(mid);
        // printf("cur %lld\n", cur);
        if(cur > k) {
            right = mid - 1;
        }
        else if(cur < k) {
            left = mid + 1;
            pmax = max(pmax, mid);
        }
        else {
            pmax = max(pmax, mid);
            break;
        }
    }
    printf("%lld\n", pmax);
}