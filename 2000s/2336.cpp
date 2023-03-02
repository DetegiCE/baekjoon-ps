#include <bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define INF 1e7

int n, ans;

typedef struct sui {
  int a, b, c;
} SUI;

bool compare(SUI p, SUI q) { return p.a < q.a; }

SUI suis[500005];
int tree[2000006];

int update(int node, int st, int en, int idx, int val) {
  if (idx < st || en < idx)
    return tree[node];
  if (st == en) {
    tree[node] = val;
    return tree[node];
  }

  int mid = (st + en) / 2;
  tree[node] = min(update(node * 2, st, mid, idx, val),
                   update(node * 2 + 1, mid + 1, en, idx, val));
  return tree[node];
}

int get(int node, int st, int en, int lef, int rig) {
  if (rig < st || en < lef)
    return INF;
  if (lef <= st && en <= rig)
    return tree[node];

  int mid = (st + en) / 2;
  return min(get(node * 2, st, mid, lef, rig),
             get(node * 2 + 1, mid + 1, en, lef, rig));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> n;
  for(int i=1 ; i<=n ; i++) {
    cin >> t;
    suis[t].a = i;
  }
  for(int i=1 ; i<=n ; i++) {
    cin >> t;
    suis[t].b = i;
  }
  for(int i=1 ; i<=n ; i++) {
    cin >> t;
    suis[t].c = i;
  }
  sort(suis+1, suis+n+1, compare);
  for (int i = 1; i <= n; i++)
    update(1, 1, n, i, INF);
  for (int i = 1; i <= n; i++) {
    if (get(1, 1, n, 1, suis[i].b) > suis[i].c)
      ans++;
    update(1, 1, n, suis[i].b, suis[i].c);
  }

  cout << ans;
}
