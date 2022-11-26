#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

map<int,int> mp;

int main()
{
    INP;
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int mx = 0;
    for(auto i: mp) {
        mx = max(mx, i.second);
    }
    cout << mx;
}