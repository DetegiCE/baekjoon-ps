#include<bits/stdc++.h>
using namespace std;

int n;
string s;

bool check() {
    int lef = 0, rig = 0;
    for(auto i: s) {
        if(i == '(') lef++;
        else rig++;
        if(rig > lef) return false;
    }
    if(lef != rig) return false;
    else return true;
}

void f(int pos) {
    if(pos == n) {
        if(check()) {
            cout << s << '\n';
            exit(0);
        }
        return;
    }
    if(s[pos] == 'G') {
        s[pos] = '(';
        f(pos+1);
        s[pos] = ')';
        f(pos+1);
    }
    else f(pos+1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;
    f(0);
}
