#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct prob {
  ll idea;
  ll impl;
} PROB;

ll n, m;
ll hidea, himpl;
ll ac, wa;

struct comparep {
  bool operator()(const PROB& a, const PROB& b) {
    if(a.impl == b.impl) return a.idea > b.idea;
    else return a.impl > b.impl;
  }
};

bool compare(PROB a, PROB b) {
  if(a.idea == b.idea) return a.impl < b.impl;
  else return a.idea < b.idea;
}

vector<PROB> v;
priority_queue<PROB, vector<PROB>, comparep> pq;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0 ; i<n ; i++) {
    PROB np;
    bool data, edit;
    cin >> np.idea >> np.impl >> data >> edit;
    if(edit) {
      np.idea = (np.idea+1)/2;
      np.impl = np.impl/2;
    }
    if(data) np.impl = 0;
    v.push_back(np);
  }
  cin >> hidea >> himpl;
  sort(v.begin(), v.end(), compare);

  ll acok = 0;
  while(ac < m) {
    while(acok < n && v[acok].idea <= hidea) {
      PROB np;
      np.idea = v[acok].idea;
      np.impl = v[acok].impl;
      pq.push(np);
      acok++;
    }
    
    if(pq.empty()) break;
    else {
      if(pq.top().impl > himpl) {
        wa += pq.top().impl - himpl;
      }
      pq.pop();
      himpl++;
      hidea++;
      ac++;
    }
  }

  if(ac < m) cout << -1;
  else cout << wa;
}
