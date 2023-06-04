#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846

double x, y;
double deg;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        x = 0, y = 0, deg = 0;
        while(n--) {
            string s;
            double d;
            cin >> s >> d;
            if(s == "lt") {
                deg += d;
            }
            else if(s == "rt") {
                deg -= d;
            }
            else if(s == "fd") {
                double dx = d * cos(deg / 180 * PI);
                double dy = d * sin(deg / 180 * PI);
                x += dx;
                y += dy;
            }
            else {
                double dx = d * cos(deg / 180 * PI);
                double dy = d * sin(deg / 180 * PI);
                x -= dx;
                y -= dy;
            }
        }
        cout << fixed;
        cout.precision(0);
        cout << sqrt(x*x+y*y) << '\n';
    }
}
