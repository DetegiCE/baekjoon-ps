#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

bool comp(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab < ba;
}

int main()
{
    INP;
   
    int n, zcnt;
    vector<string> v;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        string s;
        cin >> s;
        if(s == "0") zcnt++;
        v.PB(s);
    }
    if(zcnt == n) {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    for(int i=n-1 ; i>=0 ; i--) cout << v[i];
}