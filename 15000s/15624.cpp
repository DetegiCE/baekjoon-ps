#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MOD 1000000007

typedef long long ll;
ll a[1000001];
int main()
{
    INP;
    
    int n;
    a[1] = 1;
    cin >> n;
    for(int i=2 ; i<=n ; i++) {
        a[i] = a[i-1] + a[i-2];
        a[i] %= MOD;
    }
    cout << a[n] % MOD;
}