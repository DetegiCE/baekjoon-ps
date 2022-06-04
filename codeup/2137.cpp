#include<cstdio>

int main()
{
    int n;
    int flag = 0;
    double x;
    scanf("%d %lf", &n, &x);
    int fend = ((double)((int)x + 1) - x) * n;
    if((double)fend == ((double)((int)x + 1) - x) * n) fend--, flag = 1;
    printf("%d\n", fend);
    double ans = (double)(x - (int)x) * fend;
    printf("%.4lf\n", ans);
    ans += (double)(n * (n+1) / 2) / n;
    printf("%.4lf\n", ans);
    ans -= ((double)((int)x + 1) - x) * (n-fend);
    printf("%.4lf\n", ans - flag);
}