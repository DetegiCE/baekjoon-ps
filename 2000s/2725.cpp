#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

bool a[1003][1003];

int main()
{
    INP;
    
    int t;
    cin >> t;
    for(int j=2 ; j<=1000 ; j++) {
        for(int k=1 ; k<j ; k++) {
            if(k == 1) {
                a[j][1] = true;
                continue;
            }
            if(j % k != 0 && gcd(j, k) == 1) {
                a[j][k] = true;
            }
        }
    }
    for(int i=0 ; i<t ; i++) {
        int n, s = 3;
        cin >> n;
        for(int j=2 ; j<=n ; j++) {
            for(int k=1 ; k<j ; k++) {
                if(a[j][k]) {
                    s += 2;
                }
            }
        }
        cout << s << '\n';
    }
}