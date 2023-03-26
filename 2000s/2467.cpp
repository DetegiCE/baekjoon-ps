#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> v;

int mndif = 2e9;
int mna, mnb;

inline int _abs(int x) {
  if(x > 0) return x;
  else return -x;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for(int i=0 ; i<n ; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  
  int lef = 0, rig = n-1;
  while(lef < rig) {
    int s = v[lef] + v[rig];
    if(abs(s) < mndif) {
      mndif = abs(s);
      mna = v[lef];
      mnb = v[rig];
    }
    if(s < 0) {
      lef++;
    }
    else if(s > 0) {
      rig--;
    }
    else {
      cout << v[lef] << ' ' << v[rig];
      return 0;
    }
  }
  cout << mna << ' ' << mnb;
}
