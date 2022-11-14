#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n;
double x1, yy1, x2, y2, x3, y3, x4, y4;
double a1, a2, b1, b2;
bool infa1, infa2;

void sol() {
    cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    infa1 = infa2 = false;
    
    if(x1 == x2) infa1 = true;
    else {
        a1 = (y2-yy1)/(x2-x1);
        b1 = yy1 - a1 * x1;
    }
    
    if(x3 == x4) infa2 = true;
    else {
        a2 = (y4-y3)/(x4-x3);
        b2 = y3 - a2 * x3;
    }
    
    cout << fixed;
    cout.precision(2);
    if(a1 == 0 && !infa1 && infa2) {
        cout << "POINT " << yy1 << ' ' << x3 << '\n';
    }
    else if(a2 == 0 && !infa2 && infa1) {
        cout << "POINT " << x1 << ' ' << y3 << '\n';
    }
    else if(infa1 && infa2) {
        if(x1 == x3) cout << "LINE\n";
        else cout << "NONE\n";
    }
    else if(a1 == 0 && a2 == 0) {
        if(yy1 == y3) cout << "LINE\n";
        else cout << "NONE\n";
    }
    else {
        if(a1 == a2) {
            if(b1 == b2) cout << "LINE\n";
            else cout << "NONE\n";
            return;
        }
        
        double x = (b2 - b1) / (a1 - a2);
        double y = a1 * x + b1;
        cout << "POINT " << x << ' ' << y << '\n';
    }
}

int main()
{
    INP;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        sol();
    }
}