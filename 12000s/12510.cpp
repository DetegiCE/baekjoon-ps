#include <bits/stdc++.h>
using namespace std;

void f() {
    int n;
    cin >> n;
    int opos = 0;
    int bpos = 0;
    int otime = 0;
    int btime = 0;
    int tot = 0;
    for(int i=0 ; i<n ; i++) {
        // getchar();
        char a;
        int b;
        cin >> a >> b;
        int d;
        if(a == 'O') {
            d = max(abs(opos - b) - otime, 0) + 1;
            otime = 0;
            tot += d;
            btime += d;
            opos = b;
        }
        else {
            d = max(abs(bpos - b) - btime, 0) + 1;
            btime = 0;
            tot += d;
            otime += d;
            bpos = b;
        }
    }
    cout << tot-1 << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        cout << "Case #" << i << ": ";
        f();
    }
}