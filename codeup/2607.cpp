#include<cstdio>

bool prime[4000001];

bool isprime(int n) {
    for(int i=3 ; i*i<=n ; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i=(a%2==0?a+1:a) ; i<=b ; i+=2) {
        prime[i] = isprime(i);
    }
    for(int i=(a%2==0?a+1:a) ; i<=b ; i+=2) {
        if(prime[i] && prime[i+2]) {
            printf("%d %d\n", i, i+2);
        }
    }
    
}