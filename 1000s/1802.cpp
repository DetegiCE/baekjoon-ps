#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

string s;
    
bool f(int length) {
    if(length == 1) return true;
    for(int i=0 ; i<length/2 ; i++) {
        if(s[i] == s[length-1-i]) return false;
    }
    return f(length/2);
}

void sol() {
    cin >> s;
    if(f(s.length())) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        sol();
    }
}