#include<bits/stdc++.h>
using namespace std;

vector<int> len;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int m, n, ans = 0;
  int lef = 1, rig = 0;
  cin >> m >> n;
  for(int i=0 ; i<n ; i++) {
    int t;
    cin >> t;
    len.push_back(t);
    rig = max(rig, t);
  }
  while(lef <= rig) {
    int mid = (lef + rig) / 2;
    int cnt = 0;
    for(int i=0 ; i<n ; i++) {
      cnt += len[i] / mid;
    }
    if(cnt < m) {
      rig = mid - 1;
    }
    else {
      ans = max(ans, mid);
      lef = mid + 1;
    }
  }
  cout << ans;
}
