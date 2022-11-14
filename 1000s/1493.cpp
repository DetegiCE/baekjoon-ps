#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int l, w, h;
int n;
int c[22];
bool imp;

int f(int len, int wid, int hei) {
    if(!len || !wid || !hei) return 0;
    int mn = min(min(len, wid), hei);
    
    int mnlg = (int)log2(mn);
    while(mnlg >= 0) {
        if(c[mnlg] == 0) {
            mnlg--;
            continue;
        }
        c[mnlg]--;
        int mnv = pow(2, mnlg);
        return f(len-mnv, mnv, mnv) + f(len, wid-mnv, mnv) + f(len, wid, hei-mnv) + 1;
    }
    imp = true;
    return -1;
}

int main()
{
    INP;
    cin >> l >> w >> h;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        c[a] = b;
    }
    int ans = f(l, w, h);
    if(!imp) cout << ans;
    else cout << -1;
}