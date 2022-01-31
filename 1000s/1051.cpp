#include<cstdio>
#define MIN(A,B) (A>B?B:A)

bool check(int a, int b, int c, int d) {
    return a == b && b == c && c == d;
}

int main()
{
    int n, m;
    int a[52][52];
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    for(int size=MIN(n,m) ; size >= 2 ; size--) {
        for(int stx=0 ; stx<=n-size ; stx++) {
            for(int sty=0 ; sty<=m-size ; sty++) {
                if(check(a[stx][sty], a[stx+size-1][sty], a[stx][sty+size-1], a[stx+size-1][sty+size-1])) {
                    printf("%d", size * size);
                    return 0;
                }
            }
        }
    }
    printf("1");
}
