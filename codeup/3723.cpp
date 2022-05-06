#include<cstdio>
#define MAX(A,B) ((A)>(B)?(A):(B))

int n, ar[23];

int f(int pos, int lnk) {
    if(pos > n) return 0;
    if(lnk < 2) return MAX(f(pos+1, 0), f(pos+1, lnk+1) + ar[pos]);
    else return f(pos+1, 0);
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &ar[i]);
    }
    printf("%d", f(0, 0));
}