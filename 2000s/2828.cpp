#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int m, n;
    cin >> m >> n;
    
    int j, s = 0;
    cin >> j;
    int cst = 1;
    int cen = n;
    for(int i=0 ; i<j ; i++) {
        int x;
        cin >> x;
        if(cst <= x && x <= cen) continue;
        if(x < cst) {
            s += (cst - x);
            cen -= (cst - x);
            cst = x;
        }
        else {
            s += (x - cen);
            cst += (x - cen);
            cen = x;
        }
    }
    cout << s;
}