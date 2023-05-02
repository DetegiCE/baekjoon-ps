#include<bits/stdc++.h>
using namespace std;

int n, m, k;
string chess;
int bacc[2003][2003], wacc[2003][2003];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; i++) {
        cin.ignore();
        cin >> chess;
        for(int j=1 ; j<=m ; j++) {
            char cur = chess[j-1];
            char bcur = (i+j)%2==0?'B':'W';
            char wcur = bcur=='B'?'W':'B';
            bacc[i][j] = bacc[i-1][j] + bacc[i][j-1] - bacc[i-1][j-1] + (cur==bcur?0:1);
            wacc[i][j] = wacc[i-1][j] + wacc[i][j-1] - wacc[i-1][j-1] + (cur==wcur?0:1);
        }
    }
    
    int mnv = n*m+1;
    for(int i=1 ; i<=n-k+1 ; i++) {
        for(int j=1 ; j<=m-k+1 ; j++) {
            int bm = bacc[i+k-1][j+k-1] - bacc[i+k-1][j-1] - bacc[i-1][j+k-1] + bacc[i-1][j-1];
            int wm = wacc[i+k-1][j+k-1] - wacc[i+k-1][j-1] - wacc[i-1][j+k-1] + wacc[i-1][j-1];
            mnv = min(mnv, min(bm, wm));
        }
    }
    
    cout << mnv;
}
