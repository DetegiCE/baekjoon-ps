#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int n, tcnt = 1, mx;
string s;
vector<int> ns;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  for(int i=1 ; i<n ; i++) {
    if(s[i-1] == s[i]) tcnt++;
    else {
      ns.push_back(tcnt);
      tcnt = 1;
    }
  }
  ns.push_back(tcnt);
  for(int i=1 ; i<ns.size() ; i++) {
    mx = max(mx, min(ns[i-1], ns[i]));
  }
  cout << (mx * 2);
}
