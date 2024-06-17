#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int inn = 0;
        int c = 0;
        for(int i=0 ; i<n ; i++) {
            int p;
            cin >> p;
            if(p == 1) {
                inn++;
            }
            else {
                if(inn > 0) inn--;
                else c++;
            }
        }
        c += inn;
        cout << c << '\n';
    }
}
