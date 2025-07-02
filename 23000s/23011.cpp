#include <bits/stdc++.h>
using namespace std;

int ff(int a, int b, int c) {
    if(a-b == b-c) return 1;
    else return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        cout << "Case #" << i << ": ";
        int a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        int c1 = (d+e)/2;
        int chk1 = ff(a,b,c)+ff(d,c1,e)+ff(f,g,h)+ff(a,d,f)+ff(b,c1,g)+ff(c,e,h)+ff(a,c1,h)+ff(c,c1,f);
        int c2 = (b+g)/2;
        int chk2 = ff(a,b,c)+ff(d,c2,e)+ff(f,g,h)+ff(a,d,f)+ff(b,c2,g)+ff(c,e,h)+ff(a,c2,h)+ff(c,c2,f);
        int c3 = (a+h)/2;
        int chk3 = ff(a,b,c)+ff(d,c3,e)+ff(f,g,h)+ff(a,d,f)+ff(b,c3,g)+ff(c,e,h)+ff(a,c3,h)+ff(c,c3,f);
        int c4 = (c+f)/2;
        int chk4 = ff(a,b,c)+ff(d,c4,e)+ff(f,g,h)+ff(a,d,f)+ff(b,c4,g)+ff(c,e,h)+ff(a,c4,h)+ff(c,c4,f);
        cout << max(max(chk1, chk2), max(chk3, chk4)) << '\n';
    }
}