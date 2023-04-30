#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX(A,B) (A>B?A:B)

int n;
ll a[100005], c[100005], ans;
int q1[100005], q3[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        c[i] = c[i-1] + a[i];
    }
    if(c[n] == 0) {
        ll zcnt = 0;
        for(int i=1 ; i<=n ; i++) {
            if(c[i] == 0) zcnt++;
        }
        cout << (zcnt-1)*(zcnt-2)*(zcnt-3)/6;
        return 0;
    }
    if(c[n] % 4 != 0) {
        cout << 0;
        return 0;
    }
    
    ll m = c[n] / 4;
    for(int i=1 ; i<=n ; i++) {
        if(c[i] == m) {
            q1[i] = q1[i-1] + 1;
        }
        else q1[i] = q1[i-1];
        
        if(c[i] == m*3) {
            q3[i] = q3[i-1] + 1;
        }
        else q3[i] = q3[i-1];
    }
    
    for(int i=1 ; i<=n ; i++) {
        if(c[i] == m * 2) {
            ans += q1[i] * (q3[n] - q3[i]);
        }
    }
    cout << ans;
}
