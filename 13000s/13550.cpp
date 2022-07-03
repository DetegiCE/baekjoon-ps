#include <algorithm>
#include <cmath>
#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int n, sqrtN, sqsz;

struct Query {
    int idx, s, e;
    bool operator<(const Query &x) const {
        if (s / sqrtN != x.s / sqrtN) return s < x.s;
        return e < x.e;
    }
};

vector<Query> query;
int v[100001];
int ans[100001];

int cnt[1010001], bckcnt[400];
list<int> dq[1010001];

void add(int x, int dir) {
    auto &d = dq[v[x]];
    int cur = 0;
    if (!d.empty()) {
        cur = d.back() - d.front();
        cnt[cur]--;
        bckcnt[cur / sqrtN]--;
    }
    if (!dir)
        d.push_front(x);
    else
        d.push_back(x);
    cur = d.back() - d.front();
    cnt[cur]++;
    bckcnt[cur / sqrtN]++;
}

void sub(int x, int dir) {
    auto &d = dq[v[x]];
    int cur = d.back() - d.front();
    cnt[cur]--;
    bckcnt[cur / sqrtN]--;
    if (!dir)
        d.pop_front();
    else
        d.pop_back();
    if (!d.empty()) {
        cur = d.back() - d.front();
        cnt[cur]++;
        bckcnt[cur / sqrtN]++;
    }
}

int calc() {
    for (int i = sqsz - 1; i >= 0; i--) {
        if (!bckcnt[i]) continue;
        for (int j = sqrtN - 1; j >= 0; j--) {
            if (cnt[i * sqrtN + j]) {
                return (i * sqrtN + j);
            }
        }
    }
    return 0;
}

int main() {
    int k, q;
    scanf("%d %d", &n, &k);
    sqrtN = sqrt(n);
    sqsz = (n / sqrtN) + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        v[i] = (v[i - 1] + v[i] + k) % k;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        Query myQuery = {i, s - 1, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++) {
        add(i, 1);
    }
    ans[query[0].idx] = calc();

    for (int i = 1; i < q; i++) {
        while (s > query[i].s) add(--s, 0);
        while (e < query[i].e) add(++e, 1);
        while (s < query[i].s) sub(s++, 0);
        while (e > query[i].e) sub(e--, 1);
        ans[query[i].idx] = calc();
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
}