#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n, k;
int a[1048600];

int main()
{
    INP;
   
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];
    }
    cin >> k;
    for(int i=0 ; i<n ; i+=n/k) {
        sort(a+i, a+i+n/k);
    }
    for(int i=0 ; i<n ; i++) {
        cout << a[i] << ' ';
    }
}