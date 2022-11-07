#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, a[27][27], s[27][27], mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r;
    for(int i=1 ; i<=r ; i++) {
        for(int j=1 ; j<=i ; j++) {
            cin >> a[i][j];
        }
    }
    s[1][1] = a[1][1];
    for(int i=2 ; i<=r ; i++) {
        for(int j=1 ; j<=i ; j++) {
            if(j == 1) s[i][j] = s[i-1][j] + a[i][j];
            else if(j == i) s[i][j] = s[i-1][i-1] + a[i][j];
            else s[i][j] = max(s[i-1][j], s[i-1][j-1]) + a[i][j];
            if(i == r) mx = max(mx, s[i][j]);
        }
    }
    cout << mx;
}
