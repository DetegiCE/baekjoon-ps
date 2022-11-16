#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n;
int a[1004];
int d[1004];

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];
        d[i] = 9999;
    }
    d[0] = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<=min(i+a[i], n-1) ; j++) {
            d[j] = min(d[j], d[i]+1);
        }
    }
    if(d[n-1] == 9999) cout << -1;
    else cout << d[n-1];
}