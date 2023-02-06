#include<bits/stdc++.h>
using namespace std;

bool sieve[100001];
vector<int> prime;
int n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    prime.push_back(2);
    for(int i=3 ; i<=100000 ; i+=2) {
        if(!sieve[i]) {
            prime.push_back(i);
            for(int j=i*3 ; j<=100000 ; j+=i*2) {
                sieve[j] = true;
            }
        }
    }
    
    int t = 1;
    for(int i=2 ; i<=n ; i++) {
        int mx = 0;
        for(auto j: prime) {
            if(j > i) break;
            if(i % j == 0) {
                mx = j;
            }
        }
        // cout << i << ' ' << mx << '\n';
        if(mx <= k) t++;
    }
    cout << t;
}
