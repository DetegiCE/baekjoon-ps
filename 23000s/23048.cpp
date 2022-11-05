#include<bits/stdc++.h>
using namespace std;

int sieve[500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, no = 2;
    cin >> n;
    if(n == 1) {
        cout << "1\n1";
        return 0;
    }
    if(n == 2) {
        cout << "2\n1 2";
        return 0;
    }
    
    for(int i=3 ; i<=n ; i+=2) {
        if(sieve[i] == 0) {
            no++;
            for(int j=i ; j<=n ; j+=i*2) {
                sieve[j] = no;
            }
        }
    }
    
    cout << no << '\n';
    cout << "1 2 ";
    for(int i=3 ; i<=n ; i++) {
        if(i % 2 == 0) cout << "2 ";
        else cout << sieve[i] << ' ';
    }
}
