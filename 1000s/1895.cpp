#include<bits/stdc++.h>
using namespace std;

int r, c, t, cnt;
int img[44][44];

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> r >> c;
  for(int i=1 ; i<=r ; i++) {
    for(int j=1 ; j<=c ; j++) {
      cin >> img[i][j];
    }
  }
  cin >> t;
  for(int i=2 ; i<=r-1 ; i++) {
    for(int j=2 ; j<=c-1 ; j++) {
      vector<int> v;
      for(int di=-1 ; di<=1 ; di++) {
        for(int dj=-1 ; dj<=1 ; dj++) {
          v.push_back(img[i+di][j+dj]);
        }
      }
      sort(v.begin(), v.end());
      if(v[4] >= t) cnt++;
    }
  }
  cout << cnt;
}
