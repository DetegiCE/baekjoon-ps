#include<bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> s;
    for(int i=0 ; i<s.length() ; i++) {
        if(s[i] == 'P') {
            cnt++;
        }
        else {
            if(cnt >= 2 && s[i+1] == 'P') {
                cnt--;
                i++;
            }
            else {
                cout << "NP";
                return 0;
            }
        }
    }
    if(cnt == 1) cout << "PPAP";
    else cout << "NP";
}
