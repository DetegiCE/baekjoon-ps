#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

typedef long long ll;

// 주어진 수열에서 구간 합 구하기

int n, sqrtN, sqsz;

struct Query {
    int idx, s, e;
    bool operator<(const Query &x) const {
        if (s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
        return e < x.e;
    }
};

int conv(int a) { return a + 100000; }

vector<Query> query;
int vt[101001];
int v[101001];
ll ans[101001];

int cnt[201001], bckcnt[1000];
deque<int> dq[201001];

void add(int x, int dir) {
    int cur = 0;
    if (!dq[conv(v[x])].empty()) {
        cur = dq[conv(v[x])].back() - dq[conv(v[x])].front();
        cnt[cur]--;
        bckcnt[cur / sqrtN]--;
    }
    if (!dir)
        dq[conv(v[x])].push_front(x);
    else
        dq[conv(v[x])].push_back(x);
    cur = dq[conv(v[x])].back() - dq[conv(v[x])].front();
    cnt[cur]++;
    bckcnt[cur / sqrtN]++;
}

void sub(int x, int dir) {
    int cur = dq[conv(v[x])].back() - dq[conv(v[x])].front();
    cnt[cur]--;
    bckcnt[cur / sqrtN]--;
    if (!dir)
        dq[conv(v[x])].pop_front();
    else
        dq[conv(v[x])].pop_back();
    if (!dq[conv(v[x])].empty()) {
        cur = dq[conv(v[x])].back() - dq[conv(v[x])].front();
        cnt[cur]++;
        bckcnt[cur / sqrtN]++;
    }
}

int calc() {
    for (int i = sqsz - 1; i >= 0; i--) {
        if (bckcnt[i] == 0) continue;
        for (int j = sqrtN - 1; j >= 0; j--) {
            if (cnt[i * sqrtN + j] > 0) return (i * sqrtN + j) - 100000;
        }
    }
    return 0;
}

int main() {
    int k = 0, q;
    scanf("%d", &n);
    sqrtN = 450;
    sqsz = 201001 / sqrtN + 10;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &vt[i]);
        v[i] = v[i - 1] + vt[i];
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
        printf("%lld\n", conv(ans[i]));
    }
}