#include<bits/stdc++.h>
using namespace std;

int r, c, cnt;
bool chk;
vector<string> a;

void f(int cury, int curx) {
    if(curx == c-1)
        chk = true;
    
    a[cury][curx] = 'x';
    if(cury > 0 && a[cury-1][curx+1] == '.') {
        f(cury-1, curx+1);
        if(chk) return;
    }
    if(a[cury][curx+1] == '.') {
        f(cury, curx+1);
        if(chk) return;
    }
    if(cury < r-1 && a[cury+1][curx+1] == '.') {
        f(cury+1, curx+1);
        if(chk) return;
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin >> r >> c;
    for(int i=0 ; i<r ; i++) {
        string s;
        cin.ignore();
        cin >> s;
        a.push_back(s);
    }
    for(int i=0 ; i<r ; i++) {
        if(a[i][0] == '.') {
            chk = false;
            f(i, 0);
            if(chk) {
                cnt += 1;
            }
        }
    }
    cout << cnt;
}
