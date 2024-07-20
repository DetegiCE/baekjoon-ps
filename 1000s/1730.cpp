#include <bits/stdc++.h>
using namespace std;

int n;
string cmd;
bool ud[11][11];
bool lr[11][11];
int y, x;

int main()
{
    cin >> n;
    getline(cin, cmd);
    getline(cin, cmd);
    for(char i: cmd) {
        if(i == 'U') {
            if(y == 0) continue;
            ud[y][x] = true;
            if(y > 0) y--;
            ud[y][x] = true;
        }
        if(i == 'D') {
            if(y == n-1) continue;
            ud[y][x] = true;
            if(y < n-1) y++;
            ud[y][x] = true;
        }
        if(i == 'L') {
            if(x == 0) continue;
            lr[y][x] = true;
            if(x > 0) x--;
            lr[y][x] = true;
        }
        if(i == 'R') {
            if(x == n-1) continue;
            lr[y][x] = true;
            if(x < n-1) x++;
            lr[y][x] = true;
        }
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(ud[i][j] && lr[i][j]) cout << '+';
            else if(ud[i][j]) cout << '|';
            else if(lr[i][j]) cout << '-';
            else cout << '.';
        }
        cout << '\n';
    }
}