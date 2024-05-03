#include<bits/stdc++.h>
using namespace std;

string encode(string s) {
    string ret = "";
    for(int i=0 ; i<s.length() ; i+=2) {
        int cnt = s[i] - 48;
        int val = s[i+1] - 48;
        for(int j=0 ; j<cnt ; j++) {
            ret += (char)(val + 48);
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int k, pos;
    string s;
    cin >> k >> pos;
    getline(cin, s);
    cin >> s;
    
    while(k--) {
        s = encode(s);
    }
    cout << s[pos];
}
