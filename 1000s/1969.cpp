#include<bits/stdc++.h>
using namespace std;

int n, m;
string s;

int cnt[53][5]; // ACGT

int dna(char c) {
    if(c == 'A') return 0;
    else if(c == 'C') return 1;
    else if(c == 'G') return 2;
    else return 3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        cin >> s;
        for(int j=0 ; j<m ; j++) {
            cnt[j][dna(s[j])]++;
        }
    }
    
    int tc = 0;
    for(int i=0 ; i<m ; i++) {
        int mxv = -1;
        int mxi = -1;
        for(int j=0 ; j<4 ; j++) {
            if(cnt[i][j] > mxv) {
                mxv = cnt[i][j];
                mxi = j;
            }
        }
        if(mxi == 0) cout << "A";
        else if(mxi == 1) cout << "C";
        else if(mxi == 2) cout << "G";
        else cout << "T";
        tc += n - mxv;
    }
    cout << "\n" << tc;
}