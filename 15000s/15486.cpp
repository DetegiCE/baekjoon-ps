#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;

int n, ans;
int t[1500001];
int p[1500001];
int d[1500001];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for(int i=1 ; i<=n ; i++) {
    cin >> t[i] >> p[i];
  }

  for(int i=1 ; i<=n ; i++) {
    d[i] = max(d[i-1], d[i]);
    if(i + t[i] - 1 <= n) {
      d[i+t[i]-1] = max(d[i+t[i]-1], d[i-1] + p[i]);
    }
    ans = max(ans, d[i]);
  }
  cout << ans;
}
