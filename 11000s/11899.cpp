#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int main()
{
    INP;
    
    string s;
    cin >> s;
    int slen = s.length();
    
    int cc=0, oc=0;
    for(int i=0 ; i<slen ; i++) {
        if(s[i] == ')') {
            if(oc == 0) cc++;
            else oc--;
        }
        else {
            oc++;
        }
    }
    cout << oc + cc;
}