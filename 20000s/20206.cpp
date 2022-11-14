#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    double a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;
    
    double x1y1 = a*x1+b*y1+c;
    double x1y2 = a*x1+b*y2+c;
    double x2y1 = a*x2+b*y1+c;
    double x2y2 = a*x2+b*y2+c;
    if(x1y1 >= 0 && x1y2 >= 0 && x2y1 >= 0 && x2y2 >= 0) cout << "Lucky";
    else if(x1y1 <= 0 && x1y2 <= 0 && x2y1 <= 0 && x2y2 <= 0) cout << "Lucky";
    else cout << "Poor";
}