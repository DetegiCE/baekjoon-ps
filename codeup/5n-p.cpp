#include<cstdio>

typedef long long ll;

ll n;
ll cnt = 1;
ll mx;
ll mxcnt;

int main()
{
    scanf("%lld", &n);
    
    while(n > 1) {
        if(n > mx) {
            mx = n;
            mxcnt = cnt;
        }
        if(n % 3 == 0) {
            n /= 3;
            cnt++;
        }
        else if(n % 3 == 1) {
            n = 5 * n - 2;
            cnt++;
        }
        else {
            n = 5 * n - 1;
            cnt++;
        }
    }
    printf("%lld\n%lld %lld",cnt, mxcnt, mx);
}