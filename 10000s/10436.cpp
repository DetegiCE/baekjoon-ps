#include<bits/stdc++.h>
using namespace std;
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int i, a, b;
        char c;
        cin >> i >> a >> c >> b;
        cout << i << ' ';
        if(b == 1) {
            cout << 1 << '/' << a+1;
        }
        else if(a < b) {
            cout << b << '/' << b-a;
        }
        else {
            cout << b << '/' << (2*(a/b)+1)*b - a;
        }
        cout << '\n';
    }
}
