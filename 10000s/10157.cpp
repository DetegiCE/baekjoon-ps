#include<bits/stdc++.h>
using namespace std;

int c, r, k;
int pos[1002][1002];
int cy, cx;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> r >> k;
    if(k > c*r) {
        cout << 0;
        return 0;
    }
    cy = 1;
    cx = 1;
    int dir = 1;
    for(int i=1 ; i<=c*r ; i++) {
        pos[cy][cx] = i;
        if(dir == 1) {
            if(cx + 1 > r || pos[cy][cx+1]) {
                dir = 2;
                cy++;
            }
            else cx++;
        }
        else if(dir == 2) {
            if(cy + 1 > c || pos[cy+1][cx]) {
                dir = 3;
                cx--;
            }
            else cy++;
        }
        else if(dir == 3) {
            if(cx - 1 < 1 || pos[cy][cx-1]) {
                dir = 4;
                cy--;
            } 
            else cx--;
        }
        else {
            if(cy - 1 < 1 || pos[cy-1][cx]) {
                dir = 1;
                cx++;
            }
            else cy--;
        }
    }
    for(int i=1 ; i<=c ; i++) {
        for(int j=1 ; j<=r ; j++) {
            if(pos[i][j] == k) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << 0;
}
