#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(), A.end()

int n;
vector<int> v[5003];
int sz[5003];
ll sum;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i=0 ; i<n ; i++) {
    int a, b;
    cin >> a >> b;
    v[b-1].PB(a);
  }
  for(int i=0 ; i<5000 ; i++) {
    if(v[i].size() == 0) continue;
    sort(ALL(v[i]));
    sz[i] = v[i].size();
    if(sz[i] > 1) {
      sum += v[i][1] - v[i][0];
      sum += v[i][sz[i]-1] - v[i][sz[i]-2];
    }
  }
  for(int i=0 ; i<5000 ; i++) {
    if(v[i].size() == 0) continue;
    for(int j=1 ; j<sz[i]-1 ; j++) {
      sum += min(v[i][j] - v[i][j-1], v[i][j+1]-v[i][j]);
    }
  }
  cout << sum;
}
