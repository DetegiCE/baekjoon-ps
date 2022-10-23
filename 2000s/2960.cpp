#include<bits/stdc++.h>
using namespace std;

bool sieve[1001];
int cnt, n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=2 ; i<=n ; i++) {
        if(!sieve[i]) {
            for(int j=i ; j<=n ; j+=i) {
                if(!sieve[j]) {
                    cnt++;
                    sieve[j] = true;
                    if(cnt == k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
}