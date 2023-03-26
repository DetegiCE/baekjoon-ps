#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q, x, y;

map<ll, ll> mp;

ll a(ll pos) {
  if(pos <= 0) return 1L;
  if(mp.find(pos) != mp.end()) {
    return mp[pos];
  }
  return mp[pos] = a(pos/p-x) + a(pos/q-y);
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> p >> q >> x >> y;
  cout << a(n);
}
