#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

// 주어진 수열에서 구간 합 구하기

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator<(const Query &x) const {
        if (s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
ll res;
ll ans[100001];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    sqrtN = sqrt(n);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < q; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++) {
        res += v[i];
    }
    ans[query[0].idx] = res;

    for (int i = 1; i < q; i++) {
        while (s > query[i].s) res += v[--s];
        while (e < query[i].e) res += v[++e];
        while (s < query[i].s) res -= v[s++];
        while (e > query[i].e) res -= v[e--];
        ans[query[i].idx] = res;
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
}