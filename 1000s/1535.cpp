#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(), A.end()

int n, mx;
int l[21], J[21];
int life[22][102];

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i=1 ; i<=n ; i++) cin >> l[i];
  for(int i=1 ; i<=n ; i++) cin >> J[i];
  for(int i=1 ; i<=n ; i++) {
    for(int j=0 ; j<100 ; j++) {
      life[i][j] = life[i-1][j];
      if(j >= l[i]) {
        life[i][j] = max(life[i][j], life[i-1][j-l[i]] + J[i]);
      }
      mx = max(mx, life[i][j]);
    }
  }
  cout << mx;
}
