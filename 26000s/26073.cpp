#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

ll a, b, c, x, y, z;
ll cnt = 0;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    INP;
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, n, g, t;
        cin >> a >> b >> n;
        cin >> g;
        for(int i=1 ; i<n ; i++) {
            cin >> t;
            g = gcd(g, t);
        }
        if(a % g == 0 && b % g == 0) {
            cout << "Ta-da\n";
        }
        else cout << "Gave up\n";
    }
}