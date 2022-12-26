#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005], c[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
        c[i] = c[i-1] + a[i];
    }
    
    int q;
    cin >> q;
    for(int i=0 ; i<q ; i++) {
        int p, b;
        cin >> p >> b;
        cout << c[b] - c[p-1] << '\n';
    }
}
