#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll c = 0;
    for(ll i=1 ; i<=n ; i++) c += n % i;
    printf("%lld", n*n-c);
}