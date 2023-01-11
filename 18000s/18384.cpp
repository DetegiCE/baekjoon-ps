#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define ALL(A) A.begin(), A.end()

bool sieve[1000006];
vector<int> primes;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    primes.PB(2);
    for(int i=3 ; i<=1000000 ; i+=2) {
        if(!sieve[i]) {
            primes.PB(i);
            for(int j=i ; j<=1000000 ; j+=(i*2)) {
                sieve[j] = true;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--) {
        int s = 0;
        for(int i=0 ; i<5 ; i++) {
            int n;
            cin >> n;
            s += *lower_bound(ALL(primes), n);
        }
        cout << s << '\n';
    }
}
