#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k, p, d = 0;
    
    cin >> n >> k >> p;
    for(int i=0 ; i<n ; i++) {
        int c = 0;
        for(int j=0 ; j<k ; j++) {
            int t;
            cin >> t;
            c += (1-t);
        }
        if(c < p) d++;
    }
    cout << d;
}
