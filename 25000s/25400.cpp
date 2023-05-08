#include<bits/stdc++.h>
using namespace std;

int n, chk = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        if(t == chk) chk++;
    }
    
    cout << n-chk+1;
}
