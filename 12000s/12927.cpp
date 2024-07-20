#include <bits/stdc++.h>
using namespace std;

string cmd;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int cnt = 0;

    cin >> cmd;
    for(int i=0 ; i<cmd.size() ; i++) {
        if(cmd[i] == 'Y') {
            cnt++;
            for(int j=i ; j<cmd.size() ; j+=(i+1)) {
                if(cmd[j] == 'Y') cmd[j] = 'N';
                else cmd[j] = 'Y';
            } 
        }
    }

    int chk = 0;
    for(int i=0 ; i<cmd.size() ; i++)
        if(cmd[i] == 'Y') chk++;
    
    if(chk == 0) cout << cnt;
    else cout << -1;
}