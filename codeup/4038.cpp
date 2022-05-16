#include<cstdio>
#include<cmath>

double x1, x2, x3, wy1, y2, y3;
int up;
double s1, s2, s3, s, S;

double getSide(double xx1, double yy1, double xx2, double yy2) {
    return sqrt((xx1-xx2)*(xx1-xx2) + (yy1-yy2)*(yy1-yy2));
}

double getZero(double xx1, double yy1, double xx2, double yy2) {
    if(xx1 == xx2) return xx1;
    double tangent = (yy1-yy2)/(xx1-xx2);
    double yinter = yy1 - tangent * xx1;
    return - yinter / tangent;
}

double _abs(double x) {
    if(x >= 0) return x;
    else return -x;
}

int main()
{
    scanf("%lf %lf", &x1, &wy1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);
    if(wy1 >= 0) up++;
    if(y2 >= 0) up++;
    if(y3 >= 0) up++;
    s1 = getSide(x1, wy1, x2, y2);
    s2 = getSide(x2, y2, x3, y3);
    s3 = getSide(x3, y3, x1, wy1);
    s = (s1+s2+s3)/2;
    S = sqrt(s * (s-s1) * (s-s2) * (s-s3));

    double xlen, ylen;
    if(up == 3) {
        printf("%.0lf", S);
    }
    else if(up == 2) {
        if(wy1 < 0) {
            double x12 = (y2 == 0 ? x2 : getZero(x1, wy1, x2, y2));
            double x13 = (y3 == 0 ? x3 : getZero(x1, wy1, x3, y3));
            xlen = _abs(x12-x13);
            ylen = _abs(wy1);
        }
        else if(y2 < 0) {
            double x21 = (wy1 == 0 ? x1 : getZero(x2, y2, x1, wy1));
            double x23 = (y3 == 0 ? x3 : getZero(x2, y2, x3, y3));
            xlen = _abs(x21-x23);
            ylen = _abs(y2);
        }
        else {
            double x31 = (wy1 == 0 ? x1 : getZero(x3, y3, x1, wy1));
            double x32 = (y2 == 0 ? x2 : getZero(x3, y3, x2, y2));
            xlen = _abs(x31-x32);
            ylen = _abs(y3);
        }
        printf("%.0lf", S - (xlen * ylen) / 2);
    }
    else if(up == 1) {
        if(wy1 >= 0) {
            double x12 = (y2 == 0 ? x2 : getZero(x1, wy1, x2, y2));
            double x13 = (y3 == 0 ? x3 : getZero(x1, wy1, x3, y3));
            xlen = _abs(x12-x13);
            ylen = _abs(wy1);
        }
        else if(y2 >= 0) {
            double x21 = (wy1 == 0 ? x1 : getZero(x2, y2, x1, wy1));
            double x23 = (y3 == 0 ? x3 : getZero(x2, y2, x3, y3));
            xlen = _abs(x21-x23);
            ylen = _abs(y2);
        }
        else {
            double x31 = (wy1 == 0 ? x1 : getZero(x3, y3, x1, wy1));
            double x32 = (y2 == 0 ? x2 : getZero(x3, y3, x2, y2));
            xlen = _abs(x31-x32);
            ylen = _abs(y3);
        }
        printf("%.0lf", (xlen * ylen) / 2);
    }
    else {
        puts("0");
    }
}