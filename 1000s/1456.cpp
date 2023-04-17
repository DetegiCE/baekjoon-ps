#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> prime;
bool sieve[10000002];
ll cnt;

int main() {
    prime.push_back(2);
    for(ll i=3 ; i<10000000 ; i+=2) {
        if(!sieve[i]) {
            prime.push_back(i);
            for(ll j=i*3 ; j<=10000000 ; j+=i*2) {
                sieve[j] = true;
            } 
        }
    }
    
    ll a, b;
    cin >> a >> b;
    for(ll p: prime) {
        ll n = p * p;
        while(true) {
            if(n > b) break;
            if(a <= n) cnt++;
            if(n > b / p) break;
            n *= p;
        }
    }
    
    cout << cnt;
}
