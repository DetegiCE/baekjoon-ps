#include<cstdio>
#define MIN(A,B) (A>B?B:A)

int main()
{
    int d, p, q;
    int minv = 1000000001;
    scanf("%d %d %d", &d, &p, &q);
    if(d%p==0 || d%q==0) {
        printf("%d", d);
        return 0;
    }
    if(p < q) {
        int t = p;
        p = q;
        q = t;
    }
    int ans = (d/p)*p+p;
    int t = ans;
    for(int i=1 ; i<=t/p ; i++) {
        int left = t-p*i;
        if(left < 0) break;
        if((d-left)%q==0) {
            printf("%d", d);
            return 0;
        }
        else {
            int right = ((d-left)/q)*q+q;
            if(ans == left + right) break;
            ans = MIN(ans, left + right);
        }
    }
    printf("%d", ans);
}
