#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    INP;
    
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        cout << "Case " << i << ": ";
        int n, c = 0;
        string a, b;
        cin >> n;
        getline(cin, a);
        cin >> a >> b;
        for(int i=0 ; i<n ; i++) {
            if(a[i] != b[i]) c++;
        }
        cout << c << '\n';
    }
}