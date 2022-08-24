#include<bits/stdc++.h>
using namespace std;

double lens(double xa, double ya, double xb, double yb) {
    return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    
    double ab = lens(xa, ya, xb, yb);
    double bc = lens(xb, yb, xc, yc);
    double ca = lens(xc, yc, xa, ya);
    if((xb-xa)*(yc-ya)==(xc-xa)*(yb-ya)) {
        puts("-1");
        return 0;
    }
    double mx = max(max(ab+bc, bc+ca), ca+ab) * 2;
    double mn = min(min(ab+bc, bc+ca), ca+ab) * 2;
    printf("%.15lf", mx - mn);
}