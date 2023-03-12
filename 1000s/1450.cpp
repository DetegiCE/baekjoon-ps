#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(), A.end()

ll n, c, cnt;
vector<ll> grp1, grp2;
vector<ll> set1, set2;

void makeset(int num, int idx, ll sum) {
  if(num == 1) {
    if(idx == grp1.size()) {
      set1.PB(sum);
      return;
    }
    makeset(1, idx+1, sum);
    makeset(1, idx+1, sum+grp1[idx]);
  }
  else {
    if(idx == grp2.size()) {
      set2.PB(sum);
      return;
    }
    makeset(2, idx+1, sum);
    makeset(2, idx+1, sum+grp2[idx]);
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> n >> c;
  for(int i=0 ; i<n/2 ; i++) {
    cin >> t;
    grp1.PB(t);
  }
  for(int i=n/2 ; i<n ; i++) {
    cin >> t;
    grp2.PB(t);
  }
  if(n == 1) {
    if(grp2[0] <= c) cout << 2;
    else cout << 1;
    return 0;
  }
  makeset(1, 0, 0);
  makeset(2, 0, 0);
  sort(ALL(set1));
  sort(ALL(set2));
  // for(auto i: set1) cout << i << ' ';
  // cout << '\n';
  // for(auto i: set2) cout << i << ' ';
  // cout << '\n';
  for(ll i: set1) {
    ll val = c - i;
    cnt += upper_bound(ALL(set2), val) - set2.begin();
  }
  cout << cnt;
}
