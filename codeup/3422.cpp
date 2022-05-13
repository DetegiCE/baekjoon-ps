#include<cstdio>

typedef unsigned long long ll;
ll n;

ll two(ll a) {
    ll ret = 1;
    for(int i=0 ; i<a ; i++) {
        ret *= 2L;
    }
    return ret;
}

ll get(ll n) {
    for(int i=63 ; i>=0 ; i--) {
        if(two(i) == n) {
            return i + 1;
        }
        if(two(i) < n) {
            return get(n-two(i));
        }
    }
}

int main()
{
    scanf("%llu", &n);
    printf("%llu", get(n));
}

/*
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5

*/