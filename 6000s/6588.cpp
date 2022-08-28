#include<bits/stdc++.h>
using namespace std;

int prime[1000000];

int main()
{
    for(int i=3 ; i<=1000 ; i++) {
        if(prime[i] == 1) continue;
        for(int j=i*2 ; j<=1000000 ; j+=i) {
            prime[j] = 1;
        }
    }
    while(1) {
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i=3 ; i<=n ; i+=2) {
            if(!prime[i] && !prime[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
}