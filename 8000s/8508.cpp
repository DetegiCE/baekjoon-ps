#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define mp(A, B) make_pair(A, B)

typedef pair<int, int> pii;
queue<pii> q;

void sol() {
    vector<vector<int> > v;
    set<int> cnt[201];
    int n, k;
    int vis[201];
    scanf("%d %d", &n, &k);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        v.push_back({});
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            scanf("%d", &t);
            v[t].push_back(j);
        }
    }
    q.push(mp(0, 0));
    while (!q.empty() && q.front().second <= n) {
        int pos = q.front().first;
        int count = q.front().second;
        // printf("%d %d\n", pos, count);
        q.pop();
        for (int i : v[pos]) {
            q.push(mp(i, count + 1));
            cnt[i].insert(count + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto it = cnt[i].begin(); it != cnt[i].end(); it++) {
            vis[*it]++;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d ", vis[i]);
    // }
    // puts("");

    for (int i = 0; i < n; i++) {
        if (vis[i] == n) {
            puts("NIE");
            return;
        }
    }
    puts("TAK");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        sol();
    }
}