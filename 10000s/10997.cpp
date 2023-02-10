#include<bits/stdc++.h>
using namespace std;

int n;
char s[400][400];

void f(int lev, int pos, int glen, int slen) {
    if(lev == 1) return;
    for(int i=0 ; i<glen ; i++) s[pos][i+pos] = s[pos+slen-1][i+pos] = '*';
    for(int i=0 ; i<slen ; i++) s[i+pos][pos] = s[i+pos][pos+glen-1] = '*';
    s[pos+1][pos+glen-1] = ' ';
    s[pos+2][pos+glen-2] = '*';
    f(lev-1, pos+2, glen-4, slen-4);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    if(n == 1) {
        cout << "*";
        return 0;
    }
    for(int i=0 ; i<4*n-1 ; i++) {
        for(int j=0 ; j<4*n-3 ; j++) {
            s[i][j] = ' ';
        }
    }
    for(int i=2*n-2 ; i<2*n+1 ; i++) {
        s[i][2*(n-1)] = '*';
    }
    f(n, 0, 4*n-3, 4*n-1);
    for(int i=0 ; i<4*n-1 ; i++) {
        for(int j=0 ; j<4*n-3 ; j++) {
            cout << s[i][j];
            if(i == 1 && j == 0) break;
        }
        if(i<4*n-2) cout << '\n';
    }
}

