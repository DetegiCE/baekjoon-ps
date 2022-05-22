#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator < (const Query &x) const {
        if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
ll res;
ll ans[100001];

ll cnt[1000001];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    sqrtN = sqrt(n);
    v.resize(n+1);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=0 ; i<q ; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s ; i<=e ; i++) {
        cnt[v[i]]++;
        res -= (cnt[v[i]]-1)*(cnt[v[i]]-1)*v[i];
        res += (cnt[v[i]])*(cnt[v[i]])*v[i];
    }
    ans[query[0].idx] = res;
    
    for(int i=1 ; i<q ; i++) {
        while(s < query[i].s) {
            cnt[v[s]]--;
            res -= (cnt[v[s]]+1)*(cnt[v[s]]+1)*v[s];
            res += (cnt[v[s]])*(cnt[v[s]])*v[s];
            s++;
        }
        while(s > query[i].s) {
            s--;
            cnt[v[s]]++;
            res -= (cnt[v[s]]-1)*(cnt[v[s]]-1)*v[s];
            res += (cnt[v[s]])*(cnt[v[s]])*v[s];
        }
        while(e < query[i].e) {
            e++;
            cnt[v[e]]++;
            res -= (cnt[v[e]]-1)*(cnt[v[e]]-1)*v[e];
            res += (cnt[v[e]])*(cnt[v[e]])*v[e];
        }
        while(e > query[i].e) {
            cnt[v[e]]--;
            res -= (cnt[v[e]]+1)*(cnt[v[e]]+1)*v[e];
            res += (cnt[v[e]])*(cnt[v[e]])*v[e];
            e--;
        }
        ans[query[i].idx] = res;
    }
    for(int i=0 ; i<q ; i++) {
        printf("%lld\n", ans[i]);
    }
}