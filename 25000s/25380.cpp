// boj 25830
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB(A) push_back(A)
#define ALL(v) (v).begin(), (v).end()

int n, m, k;
ll ans;
vector<ll> police[2], pacc[2];
set<ll> r[2];

int ppos(ll val, int i, bool islef) {
  int lef = 1, rig = k;
  while(lef <= rig) {
    int mid = (lef + rig) / 2;
    if(police[i][mid] < val) lef = mid + 1;
    else rig = mid - 1;
  }
  if(police[i][lef] == val) return lef;
  if(islef) return lef;
  else return rig;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll t, t2;
  cin >> n >> m >> k;
  for(int i=0 ; i<n ; i++) {
    cin >> t;
    r[0].insert(t);
  }
  for(int i=0 ; i<m ; i++) {
    cin >> t;
    r[1].insert(t);
  }
  
  police[0].PB(0);
  police[1].PB(0);
  pacc[0].PB(0);
  pacc[1].PB(0);
  for(int i=0 ; i<k ; i++) {
    cin >> t >> t2;
    police[0].PB(t);
    police[1].PB(t2);
    pacc[0].PB(0);
    pacc[1].PB(0);
  }

  sort(police[0].begin()+1, police[0].end());
  sort(police[1].begin()+1, police[1].end());
  for(int i=1 ; i<=k ; i++) {
    pacc[0][i] = pacc[0][i-1] + police[0][i];
    pacc[1][i] = pacc[1][i-1] + police[1][i];
  }

  // get all manhattan dists
  ll tmp = 0;
  for(int i=0 ; i<2 ; i++) {
    for(int j=1 ; j<=k ; j++) {
      ll lef = police[i][j] * (j-1) - pacc[i][j-1];
      ll rig = (pacc[i][k]-pacc[i][j]) - police[i][j] * (k-j);
      tmp += (lef + rig);
    }
  }
  ans += tmp / 2;

  for(int i=0 ; i<2 ; i++) {
    for(int j=1 ; j<=k ; j++) {
      if(r[i].find(police[i][j]) != r[i].end()) continue;

      auto lef = r[i].lower_bound(police[i][j]);
      if(lef != r[i].begin()) lef--;

      auto rig = r[i].upper_bound(police[i][j]);
      if(rig == r[i].end()) rig--;

      int lidx = ppos(*lef, i, true);
      int ridx = ppos(*rig, i, false);
      if(lidx > ridx) continue;

      // over end
      if(lef == rig) {
        if(j <= ridx) {
          ll bef = ((*rig)-police[i][j])*(j-1);
          ll aft = (*rig)*(ridx-j) - (pacc[i][ridx]-pacc[i][j]);
          ans += (bef + aft);
        }
        else {
          ll bef = pacc[i][j-1] - pacc[i][lidx-1] - (*lef)*(j-lidx);
          ll aft = (police[i][j]-(*lef))*(k-j);
          ans += (bef + aft);
        }
      }
      else {
        ll cv = *rig - (police[i][j] - (*lef));
        int cidx = ppos(cv, i, false);
        if(j <= cidx) {
          ll bef = pacc[i][j-1]-pacc[i][lidx-1] - (*lef)*(j-lidx);
          ll mid = (police[i][j]-(*lef)) * (cidx-j);
          ll aft = (*rig)*(ridx-cidx) - (pacc[i][ridx]-pacc[i][cidx]);
          ans += (bef + mid + aft);
        }
        else {
          ll bef = pacc[i][cidx]-pacc[i][lidx-1] - (*lef)*(cidx-lidx+1);
          ll mid = ((*rig)-police[i][j]) * (j-cidx-1);
          ll aft = (*rig)*(ridx-j) - (pacc[i][ridx]-pacc[i][j]);
          ans += (bef + mid + aft);
        }
      }
    }
  }
  
  cout << ans;
}
