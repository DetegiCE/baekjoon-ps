#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(), A.end()

int n, sum;
int cnt[100005];
int acc[100005];

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i=0 ; i<n ; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for(int i=1 ; i<=n ; i++) {
    sum += cnt[i] / i;
    cnt[i] %= i;
  }
  for(int i=n ; i>=1 ; i--) {
    acc[i] = acc[i+1] + cnt[i];
    if(acc[i] / i > 0) {
      sum += acc[i] / i;
      acc[i] %= i;
    }
  }
  cout << sum;
}
