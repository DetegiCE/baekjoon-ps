#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q;

map<ll, ll> mp;

ll a(ll pos) {
  if(pos == 0) return 1L;
  if(mp.find(pos) != mp.end()) {
    return mp[pos];
  }
  return mp[pos] = a(pos/p) + a(pos/q);
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> p >> q;
  cout << a(n);
}
