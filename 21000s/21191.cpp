#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, a[25][25];
    cin >> n;
    string t;
    getline(cin, t);
    for(int i=0 ; i<n ; i++) {
        cin >> t;
        for(int j=0 ; j<n ; j++) {
            if(t[j] == 'W') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i=0 ; i<n ; i++) {
        int gsum = 0;
        int ssum = 0;
        for(int j=0 ; j<n ; j++) {
            gsum += a[i][j];
            ssum += a[j][i];
        }
        if(gsum != n/2 || ssum != n/2) {
            cout << 0;
            return 0;
        } 
    }
    for(int i=0 ; i<n ; i++) {
        int gchk = 0;
        int schk = 0;
        for(int j=0 ; j<n-2 ; j++) {
            if(a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2]) gchk++;
            if(a[j][i] == a[j+1][i] && a[j+1][i] == a[j+2][i]) schk++;
        }
        if(gchk != 0 || schk != 0) {
            cout << 0;
            return 0;
        }
    }
    
    cout << 1;
}

