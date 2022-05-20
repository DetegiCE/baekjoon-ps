#include<cstdio>
typedef long long ll;
typedef long double ld;
int main()
{
    int n;
    ll t;
    scanf("%d", &n);
    while(n--) {
        scanf("%lld", &t);
        if(t == 1) {
            puts("1");
            continue;
        }
        ld x = 1;
        for(int i=0 ; i<40 ; i++) {
            x = (x+t/x)/2;
        }
        ll rt = (ll)x;
        printf("%lld\n",rt*rt);
    }
}
