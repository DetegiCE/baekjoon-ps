#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

void sol() {
    int r, c;
    cin >> r >> c;
    string mapp[404];
    getline(cin, mapp[0]);
    for(int i=0 ; i<r ; i++) {
        getline(cin, mapp[i]);
    }
    
    int cnt = 0;
    for(int i=0 ; i<r ; i++) {
        for(int j=1 ; j<c-1 ; j++) {
            if(mapp[i][j-1] == '>' && mapp[i][j] == 'o' && mapp[i][j+1] == '<') cnt++;
        }
    }
    for(int i=1 ; i<r-1 ; i++) {
        for(int j=0 ; j<c ; j++) {
            if(mapp[i-1][j] == 'v' && mapp[i][j] == 'o' && mapp[i+1][j] == '^') cnt++;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    INP;
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}