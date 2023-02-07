#include<bits/stdc++.h>
using namespace std;

int r, c;
string latte[11];

bool ur(int y, int x) {
    int symin = y, symax = y, sxmin = x, sxmax = x;
    for(int i=y ; i>=0 ; i--) {
        if(latte[i][x] == '#') symin = i;
        else break;
    }
    for(int i=y ; i<r ; i++) {
        if(latte[i][x] == '#') symax = i;
        else break;
    }
    for(int i=x ; i>=0 ; i--) {
        if(latte[y][i] == '#') sxmin = i;
        else break;
    }
    for(int i=x ; i<c ; i++) {
        if(latte[y][i] == '#') sxmax = i;
        else break;
    }
    
    int dcnt = 0, scnt = 0;
    int dylen = y - symin;
    int dxlen = sxmax - x;
    if(dylen != dxlen) return false;
    for(int i=symin ; i<y ; i++) {
        for(int j=x+1 ; j<=sxmax ; j++) {
            if(latte[i][j] == '.') dcnt++;
        }
    }
    if(dcnt != dylen * dylen) return false;
    
    int sylen = symax - symin + 1;
    int sxlen = sxmax - sxmin + 1;
    if(sylen != sxlen) return false;
    for(int i=symin ; i<=symax ; i++) {
        for(int j=sxmin ; j<=sxmax ; j++) {
            if(latte[i][j] == '#') scnt++;
        }
    }
    if(scnt != sylen * sylen - dylen * dylen) return false;
    
    int odcnt = 0;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(latte[i][j] == '.') odcnt++;
        }
    }
    if(odcnt == r * c - sylen * sylen + dylen * dylen) return true;
    return false;
}

bool ul(int y, int x) {
    int symin = y, symax = y, sxmin = x, sxmax = x;
    for(int i=y ; i>=0 ; i--) {
        if(latte[i][x] == '#') symin = i;
        else break;
    }
    for(int i=y ; i<r ; i++) {
        if(latte[i][x] == '#') symax = i;
        else break;
    }
    for(int i=x ; i>=0 ; i--) {
        if(latte[y][i] == '#') sxmin = i;
        else break;
    }
    for(int i=x ; i<c ; i++) {
        if(latte[y][i] == '#') sxmax = i;
        else break;
    }
    
    int dcnt = 0, scnt = 0;
    int dylen = y - symin;
    int dxlen = x - sxmin;
    if(dylen != dxlen) return false;
    for(int i=symin ; i<y ; i++) {
        for(int j=sxmin ; j<x ; j++) {
            if(latte[i][j] == '.') dcnt++;
        }
    }
    if(dcnt != dylen * dylen) return false;
    
    int sylen = symax - symin + 1;
    int sxlen = sxmax - sxmin + 1;
    if(sylen != sxlen) return false;
    for(int i=symin ; i<=symax ; i++) {
        for(int j=sxmin ; j<=sxmax ; j++) {
            if(latte[i][j] == '#') scnt++;
        }
    }
    if(scnt != sylen * sylen - dylen * dylen) return false;
    
    int odcnt = 0;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(latte[i][j] == '.') odcnt++;
        }
    }
    if(odcnt == r * c - sylen * sylen + dylen * dylen) return true;
    return false;
}

bool lr(int y, int x) {
    int symin = y, symax = y, sxmin = x, sxmax = x;
    for(int i=y ; i>=0 ; i--) {
        if(latte[i][x] == '#') symin = i;
        else break;
    }
    for(int i=y ; i<r ; i++) {
        if(latte[i][x] == '#') symax = i;
        else break;
    }
    for(int i=x ; i>=0 ; i--) {
        if(latte[y][i] == '#') sxmin = i;
        else break;
    }
    for(int i=x ; i<c ; i++) {
        if(latte[y][i] == '#') sxmax = i;
        else break;
    }
    
    int dcnt = 0, scnt = 0;
    int dylen = symax - y;
    int dxlen = sxmax - x;
    if(dylen != dxlen) return false;
    for(int i=y+1 ; i<=symax ; i++) {
        for(int j=x+1 ; j<=sxmax ; j++) {
            if(latte[i][j] == '.') dcnt++;
        }
    }
    if(dcnt != dylen * dylen) return false;
    
    int sylen = symax - symin + 1;
    int sxlen = sxmax - sxmin + 1;
    if(sylen != sxlen) return false;
    for(int i=symin ; i<=symax ; i++) {
        for(int j=sxmin ; j<=sxmax ; j++) {
            if(latte[i][j] == '#') scnt++;
        }
    }
    if(scnt != sylen * sylen - dylen * dylen) return false;
    
    int odcnt = 0;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(latte[i][j] == '.') odcnt++;
        }
    }
    if(odcnt == r * c - sylen * sylen + dylen * dylen) return true;
    return false;
}

bool ll(int y, int x) {
    int symin = y, symax = y, sxmin = x, sxmax = x;
    for(int i=y ; i>=0 ; i--) {
        if(latte[i][x] == '#') symin = i;
        else break;
    }
    for(int i=y ; i<r ; i++) {
        if(latte[i][x] == '#') symax = i;
        else break;
    }
    for(int i=x ; i>=0 ; i--) {
        if(latte[y][i] == '#') sxmin = i;
        else break;
    }
    for(int i=x ; i<c ; i++) {
        if(latte[y][i] == '#') sxmax = i;
        else break;
    }
    
    int dcnt = 0, scnt = 0;
    int dylen = symax - y;
    int dxlen = x - sxmin;
    if(dylen != dxlen) return false;
    for(int i=y+1 ; i<=symax ; i++) {
        for(int j=sxmin ; j<x ; j++) {
            if(latte[i][j] == '.') dcnt++;
        }
    }
    if(dcnt != dylen * dylen) return false;
    
    int sylen = symax - symin + 1;
    int sxlen = sxmax - sxmin + 1;
    if(sylen != sxlen) return false;
    for(int i=symin ; i<=symax ; i++) {
        for(int j=sxmin ; j<=sxmax ; j++) {
            if(latte[i][j] == '#') scnt++;
        }
    }
    if(scnt != sylen * sylen - dylen * dylen) return false;
    
    int odcnt = 0;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(latte[i][j] == '.') odcnt++;
        }
    }
    if(odcnt == r * c - sylen * sylen + dylen * dylen) return true;
    return false;
}

void f() {
    cin >> r >> c;
    cin.ignore();
    for(int i=0 ; i<r ; i++) cin >> latte[i];
    
    // upper right
    for(int i=0 ; i<r-1 ; i++) {
        for(int j=0 ; j<c-1 ; j++) {
            if(latte[i][j] == '#' && latte[i+1][j] == '#' 
                && latte[i][j+1] == '.' && latte[i+1][j+1] == '#') {
                if(ur(i+1, j)) {
                    cout << "1\n";
                    return;
                }   
            }
        }
    }
    // upper left
    for(int i=0 ; i<r-1 ; i++) {
        for(int j=0 ; j<c-1 ; j++) {
            if(latte[i][j] == '.' && latte[i+1][j] == '#' 
                && latte[i][j+1] == '#' && latte[i+1][j+1] == '#') {
                if(ul(i+1, j+1)) {
                    cout << "1\n";
                    return;
                }   
            }
        }
    }
    // lower right
    for(int i=0 ; i<r-1 ; i++) {
        for(int j=0 ; j<c-1 ; j++) {
            if(latte[i][j] == '#' && latte[i+1][j] == '#' 
                && latte[i][j+1] == '#' && latte[i+1][j+1] == '.') {
                if(lr(i, j)) {
                    cout << "1\n";
                    return;
                }   
            }
        }
    }
    // lower left
    for(int i=0 ; i<r-1 ; i++) {
        for(int j=0 ; j<c-1 ; j++) {
            if(latte[i][j] == '#' && latte[i+1][j] == '.' 
                && latte[i][j+1] == '#' && latte[i+1][j+1] == '#') {
                if(ll(i, j+1)) {
                    cout << "1\n";
                    return;
                }   
            }
        }
    }
    cout << "0\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        f();
    }
}
