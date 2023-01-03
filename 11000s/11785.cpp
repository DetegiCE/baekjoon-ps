#include<bits/stdc++.h>
using namespace std;

int a[21], c[21], d[21];
        
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int tc=1 ; tc<=t ; tc++) {
        int n, l;
        cin >> n >> l;
        for(int i=1 ; i<=n ; i++) {
            cin >> a[i];
            c[i] = c[i-1] + a[i];
            d[i] = d[i+1] + c[i];
        }
        sort(a+1, a+n+1);
        for(int i=1 ; i<=n ; i++) {
            c[i] = c[i-1] + a[i];
            d[i] = d[i-1] + c[i];
        }
        a[n+1] = 0;
        c[n+1] = c[n];
        d[n+1] = d[n];
        cout << "Case " << tc << ": ";
        
        if(a[1] > l) {
            cout << "0 0 0\n";
            continue;
        }
        int flg = 0;
        for(int i=1 ; i<=n ; i++) {
            if(c[i] <= l && l < c[i+1]) {
                cout << i << ' ' << c[i] << ' ' << d[i] << '\n';
                flg = 1;
                break;
            }
        }
        if(flg == 0) {
            cout << n << ' ' << c[n] << ' ' << d[n] << '\n';
        }
    }
}
