#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string t[4];
int k;

void rotate(int cur, int dir) {
    if(dir == 1) {
        char tmp = t[cur][7];
        for(int i=7 ; i>=1 ; i--) {
            t[cur][i] = t[cur][i-1];
        }
        t[cur][0] = tmp;
    }
    else {
        char tmp = t[cur][0];
        for(int i=0 ; i<=6 ; i++) {
            t[cur][i] = t[cur][i+1];
        }
        t[cur][7] = tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0 ; i<4 ; i++) cin >> t[i];
    cin >> k;
    for(int i=0 ; i<k ; i++) {
        int rot[4] = {0,0,0,0};
        int a, b;
        cin >> a >> b;
        a--;
        rot[a] = b;
        for(int j=a-1 ; j>=0 ; j--) {
            if(t[j+1][6] == t[j][2]) break;
            else rot[j] = -rot[j+1];
        }
        for(int j=a+1 ; j<4 ; j++) {
            if(t[j-1][2] == t[j][6]) break;
            else rot[j] = -rot[j-1];
        }
        for(int j=0 ; j<4 ; j++) {
            if(rot[j] != 0) rotate(j, rot[j]);
        }
    }
    
    int sc = 0;
    for(int i=0 ; i<4 ; i++) {
        if(t[i][0] == '1') sc += (1<<i);
    }
    cout << sc;
}