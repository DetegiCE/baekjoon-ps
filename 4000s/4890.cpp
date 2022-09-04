#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b?gcd(b, a%b):a;
}

int main()
{
    while(1) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll l = a * b / gcd(a,b);
        if(a == 0) break;
        printf("%lld\n", l/a*l/b);
    }
}