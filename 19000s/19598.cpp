#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int n, cnt, mx;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i=0 ; i<n ; i++) {
    int a, b;
    cin >> a >> b;
    pq.push(MP(a,1));
    pq.push(MP(b,0));
  }
  while(!pq.empty()) {
    pii pt = pq.top();
    pq.pop();
    if(pt.second == 1) cnt++;
    else cnt--;
    mx = max(mx, cnt);
  }
  cout << mx;
}
