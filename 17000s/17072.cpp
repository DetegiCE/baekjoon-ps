#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            int r, g, b;
            cin >> r >> g >> b;
            int v = 2126 * r + 7152 * g + 722 * b;
            if(v < 510000) cout << '#';
            else if(v < 1020000) cout << 'o';
            else if(v < 1530000) cout << '+';
            else if(v < 2040000) cout << '-';
            else cout << '.';
        }
        cout << '\n';
    }
}
