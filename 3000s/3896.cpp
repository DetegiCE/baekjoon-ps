#include<bits/stdc++.h>
using namespace std;

vector<int> v;
bool sieve[1300000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    v.push_back(2);
    for(int i=3 ; i<=1299709 ; i+=2) {
        if(!sieve[i]) {
            v.push_back(i);
            for(int j=i ; j<=1299709 ; j+=i*2) {
                sieve[j] = true;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) cout << 0;
        else if(binary_search(v.begin(), v.end(), n)) cout << 0;
        else {
            int lwb = lower_bound(v.begin(), v.end(), n) - v.begin();
            cout << v[lwb] - v[lwb-1];
        }
        cout << '\n';
    }
}
