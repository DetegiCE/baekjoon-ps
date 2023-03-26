#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a, c;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> q;
  a.push_back(0);
  c.push_back(0);
  for(int i=0 ; i<n ; i++) {
    int t;
    cin >> t;
    a.push_back(t);
    c.push_back(t ^ c[i]);
  }

  int x = 0;
  for(int i=0 ; i<q ; i++) {
    int s, e;
    cin >> s >> e;
    x ^= (c[s-1] ^ c[e]);
  }
  cout << x;
}
