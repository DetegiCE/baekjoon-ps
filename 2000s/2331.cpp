#include<bits/stdc++.h>
using namespace std;

int a, p, cnt;
map<int, int> mp;

int _pow(int a, int b) {
    int t = a;
    for(int i=0 ; i<b-1 ; i++) t *= a;
    return t;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> p;
    mp[a] = ++cnt;
    while(true) {
        int n = 0;
        while(a) {
            n += _pow(a%10, p);
            a /= 10;
        }
        a = n;
        if(mp.find(a) == mp.end()) {
            mp[a] = ++cnt;
        }
        else {
            cout << mp[a] - 1;
            return 0;
        }
    }
}
