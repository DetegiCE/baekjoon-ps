#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MOD 1000000007

typedef long long ll;

ll two[32];

void sol() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    n -= 2;
    
    ll sum = 1;
    for(int i=0 ; i<31 ; i++) {
        if(n & (1 << i)) sum *= two[i+1]; 
        sum %= MOD;
    }
    cout << sum % MOD << '\n';
}

void twos() {
    two[0] = 1;
    two[1] = 2;
    for(int i=2 ; i<32 ; i++) {
        two[i] = two[i-1] * two[i-1];
        two[i] %= MOD;
    }
}

int main()
{
    INP;
    
    twos();
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}