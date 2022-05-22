#include<cstdio>

int main()
{
    int n, p[101], g = 0;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &p[i]);
        g ^= p[i];
    }
    printf("%s", g==0?"cubelover":"koosaga");
}