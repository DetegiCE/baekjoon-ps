#include<bits/stdc++.h>
using namespace std;

bool sieve[1000001];
vector<int> prime;

void makeprime(int v) {
    sieve[0] = sieve[1] = true;
    for(int i=3 ; i<=v ; i+=2) {
        if(!sieve[i]) {
            prime.push_back(i);
            for(int j=i*3 ; j<=v ; j += i*2) {
                sieve[j] = true;
            }
        }
    }
}

int main()
{
    
    int n;
    scanf("%d", &n);
    makeprime(n);
    if(n < 8) puts("-1");
    else if(n == 8) puts("2 2 2 2");
    else if(n % 2 == 1) {
        if(!sieve[n-6]) {
            printf("2 2 2 %d", n-6);
            return 0;
        }
        else {
            int m = n - 2;
            for(int i=0 ; i<prime.size() ; i++) {
                int o = m - prime[i];
                for(int j=0 ; j<prime.size() && prime[j] <= o / 2 ; j++) {
                    if(!sieve[o-prime[j]]) {
                        printf("2 %d %d %d", prime[i], prime[j], o-prime[j]);
                        return 0;
                    }
                }
            }
        }
        puts("-1");
    }
    else {
        prime.push_back(2);
        for(int i=0 ; i<prime.size() ; i++) {
            for(int j=i ; j<prime.size() ; j++) {
                int m = n - prime[i] - prime[j];
                for(int k=0 ; k<prime.size() && prime[k] <= m / 2 ; k++) {
                    if(!sieve[m-prime[k]]) {
                        printf("%d %d %d %d", prime[i], prime[j], prime[k], m-prime[k]);
                        return 0;
                    }
                }
            }
        }
        puts("-1");
    }
}