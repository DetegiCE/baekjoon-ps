#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

int main()
{
    INP;
    int n;
    cin >> n;
    
    ll a[100001], b[100001];
    ll x = 0, y = 0;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n);
    
    for(int i=0 ; i<n/2 ; i++) {
        x += a[n-i-1] - a[i];
        y += b[n-i-1] - b[i];
    }
    cout << x + y;
}
