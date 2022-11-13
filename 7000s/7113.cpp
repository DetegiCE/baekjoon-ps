#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    INP;
    
    int n, m, c = 1;
    cin >> n >> m;
    
    while(n != m) {
        if(n > m) {
            c += n/m;
            n %= m;
            if(n == 0) {
                c--;
                break;
            }
        }
        else {
            c += m/n;
            m %= n;
            if(m == 0) {
                c--;
                break;
            }
        }
    }
    cout << c;
}