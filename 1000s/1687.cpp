#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int mp[340][340];
int ac[340][340];
int nr[340];
int mx;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        string s;
        cin >> s;
        for(int j=1 ; j<=m ; j++) {
            mp[i][j] = s[j-1]-48;
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + mp[i][j];
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=i ; j<=n ; j++) {
            for(int k=1 ; k<=m ; k++) {
                nr[k] = ac[j][k] - ac[i-1][k];
            }
            for(int k=1 ; k<=m ; k++) {
                if(nr[k-1] == nr[k]) {
                    int pos = upper_bound(nr+1, nr+m+1, nr[k]) - nr - 1;
                    mx = max(mx, (j-i+1)*(pos-k+1));
                }
            }
        }
    }
    
    cout << mx;
}
