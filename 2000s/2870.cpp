#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> v;
    
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        string t = "";
        for(int i=0 ; i<s.length() ; i++) {
            if('a' <= s[i] && s[i] <= 'z') {
                if(t != "") {
                    if(t[0] != '0' || (t.length() == 1 && t[0] == '0'))
                        v.push_back(t);
                    else {
                        while(t[0] == '0' && t.length() > 1) {
                            t = t.substr(1, t.length()-1);
                        }
                        v.push_back(t);
                    }
                }
                t = "";
                continue;
            }
            if(t == "") t = s[i];
            else {
                t += s[i];
            }
        }
        if(t == "") continue;
        if(t[0] != '0' || (t.length() == 1 && t[0] == '0'))
            v.push_back(t);
        else {
            while(t[0] == '0' && t.length() > 1) {
                t = t.substr(1, t.length()-1);
            }
            v.push_back(t);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(auto i: v) {
        cout << i << '\n';
    }
}