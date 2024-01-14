#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    while(true) {
        int n, p[102], s = 0, mx = 0;
        cin >> n;
        if(n == 0) break;
        for(int i=0 ; i<n ; i++) {
            cin >> p[i];
            s += p[i];
            mx = max(mx, p[i]);
        }
        for(int i=50 ; i<=70 ; i+=10) {
            int c = i/mx+1;
            if(c < 2 || i < s * 2) cout << "0 ";
            else cout << c << ' ';
        } 
        cout << '\n';
    }
}
