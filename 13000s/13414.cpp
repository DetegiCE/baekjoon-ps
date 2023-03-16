#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, l, dupl;
typedef struct stu {
  string stn;
  int ord;
} STU;

map<string, int> mp;
vector<STU> v;

bool compare(STU a, STU b) {
  return a.ord < b.ord;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> k >> l;
  for(int i=0 ; i<l ; i++) {
    string stn;
    cin.ignore();
    cin >> stn;

    auto f = mp.find(stn);
    if(f != mp.end()) {
      // cout << i << ' ' << "a\n";
      v[(get<1>(*f))].ord = i;
      dupl++;
    }
    else {
      // cout << i << ' ' << "b\n";
      mp[stn] = i - dupl;
      STU nst;
      nst.stn = stn;
      nst.ord = i;
      v.push_back(nst);
    }
  }

  // for(auto m: mp) {
  //   cout << get<0>(m) << ' ' << get<1>(m) << '\n';
  // }
  // cout << "============\n";
  // for(auto m: v) {
  //   cout << m.stn << ' ' << m.ord << '\n';
  // }

  sort(v.begin(), v.end(), compare);

  int vsz = v.size();
  for(int i=0 ; i<min(vsz, k) ; i++) {
    cout << v[i].stn << '\n';
  }
}
