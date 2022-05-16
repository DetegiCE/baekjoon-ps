#include<cstdio>

#define MIN(A,B) (A>B?B:A)

int ar[1002][1002];
int ac[1002][1002];
int mx = 0;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            scanf("%1d", &ar[i][j]);
            if(ar[i][j]) mx = 1;
            ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + ar[i][j];
        }
    }
    if(mx == 0) {
        puts("0");
        return 0;
    }
    for(int k=2 ; k<=MIN(n, m) ; k++) {
        for(int i=1 ; i<=n-k+1 ; i++) {
            for(int j=1 ; j<=m-k+1 ; j++) {
                int area = ac[i+k-1][j+k-1] - ac[i-1][j+k-1] - ac[i+k-1][j-1] + ac[i-1][j-1];
                if(area == k*k) {
                    mx = k;
                }
            }
        }
    }
    printf("%d\n", mx*mx);
}