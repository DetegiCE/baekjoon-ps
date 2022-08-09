#include<cstdio>

int main()
{
    int cnt = 0;
    while(1) {
        cnt++;
        double d, r, t;
        scanf("%lf %lf %lf", &d, &r, &t);
        if(r == 0) break;
        double dist = 3.1415927 * d * r / 12 / 5280;
        double mph = dist * (3600 / t);
        printf("Trip #%d: %.2lf %.2lf\n", cnt, dist, mph);
    }
}