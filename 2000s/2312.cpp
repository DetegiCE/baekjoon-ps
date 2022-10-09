#include<bits/stdc++.h>
using namespace std;

bool sieve[100001];
vector<int> prime;

void makeprime(int v) {
    prime.push_back(2);
    for(int i=3 ; i<=v ; i+=2) {
        if(!sieve[i]) {
            prime.push_back(i);
            for(int j=i*3 ; j<=v ; j += i*2) {
                sieve[j] = true;
            }
        }
    }
}

void sol() {
    int m;
    scanf("%d", &m);
    for(int i=0 ; i<prime.size() ; i++) {
        int cnt = 0;
        while(m % prime[i] == 0) {
            cnt++;
            m /= prime[i];
        }
        if(cnt > 0) printf("%d %d\n", prime[i], cnt);
        if(m == 1) break;
    }
}

int main()
{
    makeprime(100000);
    
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        sol();
    }
}