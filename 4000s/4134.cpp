#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int t;

bool isprime(ll k) {
  for(ll i=3 ; i*i<=k ; i+=2) {
    if(k % i == 0) return false;
  }
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while(t--) {
    cin >> n;
    if(n <= 2) {
      cout << "2\n";
      continue;
    }
    if(!(n&1)) n++;
    for(ll i=n ;; i+=2) {
      if(isprime(i)) {
        cout << i << '\n';
        break;
      }
    }
  }
}
