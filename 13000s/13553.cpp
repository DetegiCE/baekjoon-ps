#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

#define MIN(A,B) (A>B?B:A)
#define MAX(A,B) (A>B?A:B)
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
int cntTree[100001];

void update(int idx, int val) {
    while(idx < 100001) {
        cntTree[idx] += val;
        idx += (idx & -idx);
    }
}

ll getSumFromZero(int idx) {
    ll ret = 0;
    while(0 < idx) {
        ret += cntTree[idx];
        idx &= (idx-1);
    }
    return ret;
}

ll getSum(int st, int en) {
    return getSumFromZero(en) - getSumFromZero(st-1);
}

int main()
{
    int n, k, q;
    scanf("%d %d", &n, &k);
    sqrtN = sqrt(n);
    v.resize(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    scanf("%d", &q);
    for(int i=0 ; i<q ; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s ; i<=e ; i++) {
        if(i-s) {
            res += getSum(MAX(0, v[i]-k), MIN(100000, v[i]+k));
        }
        update(v[i], 1);
    }
    ans[query[0].idx] = res;
    // printf("%d %d %lld\n", s, e, ans[query[0].idx]);

    for(int i=1 ; i<q ; i++) {
        while(s < query[i].s) {
            update(v[s], -1);
            res -= getSum(MAX(0, v[s]-k), MIN(100000, v[s]+k));
            s++;
        }
        while(s > query[i].s) {
            s--;
            res += getSum(MAX(0, v[s]-k), MIN(100000, v[s]+k));
            update(v[s], 1);
        }
        while(e < query[i].e) {
            e++;
            res += getSum(MAX(0, v[e]-k), MIN(100000, v[e]+k));
            update(v[e], 1);
        }
        while(e > query[i].e) {
            update(v[e], -1);
            res -= getSum(MAX(0, v[e]-k), MIN(100000, v[e]+k));
            e--;
        }
        ans[query[i].idx] = res;
        // printf("%d %d %lld\n", query[i].s, query[i].e, ans[query[i].idx]);
    }
    for(int i=0 ; i<q ; i++) {
        printf("%lld\n", ans[i]);
    }
}