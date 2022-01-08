#include<cstdio>
#include<cmath>

int main()
{
    double d, h, w;
    scanf("%lf %lf %lf", &d, &h, &w);
    double x = sqrt(d*d/(h*h+w*w));
    printf("%.0lf %.0lf", floor(x*h), floor(x*w));
}
