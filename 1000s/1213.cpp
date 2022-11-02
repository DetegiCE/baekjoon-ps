#include<bits/stdc++.h>
using namespace std;

int cnt[30];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(int i=0 ; i<s.length() ; i++) {
        cnt[s[i]-'A']++;
    }
    
    int ec = 0, oc = 0;
    for(int i=0 ; i<26 ; i++) {
        if(cnt[i] % 2 == 0) ec++;
        else oc++;
    }
    if(oc == 0) {
        for(int i=0 ; i<26 ; i++) {
            char s = i + 'A';
            for(int j=0 ; j<cnt[i]/2 ; j++) cout << s;
        }
        for(int i=25 ; i>=0 ; i--) {
            char s = i + 'A';
            for(int j=0 ; j<cnt[i]/2 ; j++) cout << s;
        }
    }
    else if(oc == 1) {
        char c;
        for(int i=0 ; i<26 ; i++) {
            if(cnt[i] % 2 == 1) {
                c = i + 'A';
                break;
            }
        }
        for(int i=0 ; i<26 ; i++) {
            char s = i + 'A';
            for(int j=0 ; j<cnt[i]/2 ; j++) cout << s;
        }
        cout << c;
        for(int i=25 ; i>=0 ; i--) {
            char s = i + 'A';
            for(int j=0 ; j<cnt[i]/2 ; j++) cout << s;
        }
    }
    else {
        cout << "I\'m Sorry Hansoo";
    }
}