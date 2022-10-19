#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

bool check(string s) {
    int slen = s.length();
    if(slen == 1) return true;
    
    string left, rght;
    
    left = s.substr(0, slen/2);
    rght = s.substr(slen/2+(slen%2==0?0:1), slen/2);
    if(left != rght) return false;
    return (check(left) && check(rght));
}

int main(){
    INP;
    
    string s;
    cin >> s;

    if(check(s)) cout << "AKARAKA";
    else cout << "IPSELENTI";
}