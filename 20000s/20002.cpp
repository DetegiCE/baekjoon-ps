#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int ar[303][303];
int ac[303][303];

int main(){
    INP;
    
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> ar[i][j];
            ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + ar[i][j];
        }
    }
    
    int mx = -10000;
    for(int sz=1 ; sz<=n ; sz++) {
        for(int i=1 ; i<=n-sz+1 ; i++) {
            for(int j=1 ; j<=n-sz+1 ; j++) {
                int cur = ac[i+sz-1][j+sz-1] - ac[i-1][j+sz-1] - ac[i+sz-1][j-1] + ac[i-1][j-1];
                mx = max(mx, cur);
            }
        }
    }
    
    cout << mx;
}