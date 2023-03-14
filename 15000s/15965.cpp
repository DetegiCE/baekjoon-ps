#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define PMX 7500000

bool sieve[PMX];
vector<int> v;
int k;

int main()
{
  v.PB(0);
  v.PB(2);
  for(int i=3 ; i<PMX ; i+=2) {
    if(!sieve[i]) {
      v.PB(i);
      for(int j=i*3 ; j<PMX ; j+=(i<<1)) {
        sieve[j] = true;
      }
    }
  }
  cin >> k;
  cout << v[k];
}
