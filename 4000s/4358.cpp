#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> m;
    string s;
    int t = 0;
    while(getline(cin, s)) {
        m[s]++;
        t++;
    }
    
    cout << fixed;
    cout.precision(4);
    for(auto elem: m) {
        cout << elem.first << " " << ((double)elem.second/t)*100 << '\n';
    }
}