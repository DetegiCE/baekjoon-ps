#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int a = 1;
    for(int i=2 ; i*i<=n ; i++) {
        if(i * i == n) {
            a += i;
            break;
        }
        if(n % i == 0) {
            a += i;
            a += n/i;
        }
    }
    return a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        if(a == 1) {
            cout << "deficient\n";
            continue;
        }
        int b = f(a);
        if(b > a) cout << "abundant\n";
        else if(b < a) cout << "deficient\n";
        else cout << "perfect\n";
    }
    
}