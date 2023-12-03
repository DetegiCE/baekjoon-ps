#include<bits/stdc++.h>
using namespace std;

int t;
int v[192000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    for(int i=3 ; i<=191230 ; i++) {
        v[i] = v[i-1] + v[i-2];
        v[i] %= 1000000007;
    }
    while(t--) {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }
}
