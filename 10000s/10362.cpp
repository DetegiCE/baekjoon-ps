#include<bits/stdc++.h>
using namespace std;

void f() {
    int b[150][150];
    int sx = 75, sy = 75;
    int x, y;
    cin >> x >> y;
    sx += x;
    sy += y;
    for(int i=0 ; i<150 ; i++) {
        for(int j=0 ; j<150 ; j++) {
            b[i][j] = 0;
        }
    }
    b[sx][sy]++;
    
    string s;
    cin >> s;
    int dir = 0; // up left down right
    for(char c: s) {
        if(c == 'F') {
            if(dir == 0) sy++;
            if(dir == 1) sx--;
            if(dir == 2) sy--;
            if(dir == 3) sx++;
            b[sx][sy]++;
        }
        if(c == 'L') {
            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 3;
            else dir = 0;
        }
        if(c == 'R') {
            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 0;
            else if(dir == 2) dir = 1;
            else dir = 2;
        }
        
    }
    
    int cnt = 0;
    for(int i=0 ; i<150 ; i++) {
        for(int j=0 ; j<150 ; j++) {
            if(b[i][j] > 1) cnt++;
        }   
    }
    cout << sx-75 << ' ' << sy-75 << ' ' << cnt << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cout << "Case #" << i << ": ";
        f();
    }
}
