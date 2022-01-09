#include<cstdio>

int main()
{
    int d, h, m;
    scanf("%d %d %d", &d, &h, &m);
    int t = d * 1440 + h * 60 + m - 11 * 1501;
    printf("%d", t>=0?t:-1);
}
