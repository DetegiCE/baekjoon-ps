#include<cstdio>

int _abs(int a) {
    if(a >= 0) return a;
    else return -a;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if(k == 0) {
            printf("%d\n", n%2);
        }
        else {
            if(k-n < 0) printf("%d\n", _abs(k-n)%2);
            else printf("%d\n", k-n);
        }
    }
}