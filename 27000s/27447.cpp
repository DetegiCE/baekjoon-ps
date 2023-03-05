#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> t;
int tim[1000006];
priority_queue<int> pq;
int s[4];

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0 ; i<n ; i++) {
    int tt;
    cin >> tt;
    t.push_back(tt);
    pq.push(tt-m);
    tim[tt] = 1;
  }
  s[0] = s[1] = s[2] = n;

  for(int i=t[n-1] ; i>=0 ; i--) {
    if(tim[i] == 1) {
      // cout << i << " 2\n";
      s[2]--;
    }
    else if(!pq.empty() && pq.top() <= i && i <= pq.top() + m) {
      // cout << i << " 1\n";
      s[1]--;
      pq.pop();
    }
    else {
      s[0]--;
    }
  }

  // cout << s[0] << ' ' << s[1] << ' ' << s[2] << '\n';
  if(s[0]>0 || s[1]>0 || s[2]>0) cout << "fail";
  else cout << "success";
}
