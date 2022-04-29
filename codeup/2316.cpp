#include<cstdio>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        int cnt = 0;
        int j;
        for(j=1 ; j*j<t ; j++) {
            if(t % j == 0) cnt+=2;
        }
        if(j*j == t) cnt++;
        printf("%d\n", cnt + m/t - 1);
    }
}