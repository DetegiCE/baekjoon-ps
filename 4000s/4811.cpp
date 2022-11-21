#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
#define MOD 987654321
typedef long long ll;

ll c[31];

int main() 
{
    INP;
    c[0] = 1;
    c[1] = 1;
    c[2] = 2;
    c[3] = 5;
    c[4] = 14;
    for(ll i=5 ; i<=30 ; i++) {
        for(ll j=0 ; j<i ; j++) {
            c[i] += c[j] * c[i-1-j];
        }
    }
    
    while(true) {
        int t;
        cin >> t;
        if(t == 0) break;
        cout << c[t] << '\n';
    }
    
}