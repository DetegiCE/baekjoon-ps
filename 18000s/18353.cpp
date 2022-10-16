#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

int main()
{
      scanf("%d",&n);
      v.push_back(0);

      int num;
      int a[2001];
      for(int i=0 ; i<n ; i++) {
          scanf("%d", &a[n-i-1]);
      }
      for(int i=0 ; i<n ; i++) {
          num = a[i];
          if(num > v.back()) v.push_back(num);
          else {
              int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
              v[idx] = num;
          }
      }

      printf("%d",n-v.size()+1);
}