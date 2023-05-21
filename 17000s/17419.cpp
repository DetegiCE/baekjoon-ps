#include<bits/stdc++.h>
using namespace std;

int k, c;
string s;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    cin.ignore();
    cin >> s;
    for(int i=0 ; i<k ; i++) {
        if(s[i] == '1') c++;
    }
    cout << c;
}
