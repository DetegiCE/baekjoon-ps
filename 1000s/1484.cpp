#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int g;
    cin >> g;
    
    int flg = 0;
    for(int i = sqrt(g) ; i >= 1 ; i--) {
        if(i * (g/i) == g) {
            int a = g/i;
            int b = i;
            if((a != b) && (a+b)%2==0 && (a-b)%2==0) {
                cout << (a+b)/2 << '\n';
                flg = 1;
            }
        }
    }
    if(flg == 0) cout << -1;
}