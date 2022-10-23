#include<bits/stdc++.h>
using namespace std;

int n;
int a[100003];
int c[100003], d[100003];

int mx = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        c[i] = c[i-1] + a[i];
    }
    for(int i=n ; i>=1 ; i--) {
        d[i] = d[i+1] + a[i];
    }
    for(int i=1 ; i<=n ; i++) {
        if(i != n) mx = max(mx, c[n-1] + c[i-1] - a[i]);
        if(i != 1) mx = max(mx, d[2] + d[i+1] - a[i]);
        if(i != 1 && i != n) mx = max(mx, c[n] - a[1] - a[n] + a[i]);
    }
    cout << mx;
}