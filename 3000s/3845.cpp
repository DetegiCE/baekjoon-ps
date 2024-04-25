#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int nx, ny;
    double w;
    while(true) {
        cin >> nx >> ny >> w;
        if(w == 0) break;
        
        vector<double> vx, vy;
        for(int i=0 ; i<nx ; i++) {
            double t;
            cin >> t;
            vx.push_back(t);
        }
        sort(vx.begin(), vx.end());
        bool chkx = (vx[0] <= w/2) && (75 - vx[nx-1] <= w/2);
        for(int i=0 ; i<nx-1 ; i++) {
            if(!chkx) break;
            if(vx[i+1] - vx[i] > w)
                chkx = false;
        }
        
        for(int i=0 ; i<ny ; i++) {
            double t;
            cin >> t;
            vy.push_back(t);
        }
        sort(vy.begin(), vy.end());
        bool chky = (vy[0] <= w/2) && (100 - vy[ny-1] <= w/2);
        for(int i=0 ; i<ny-1 ; i++) {
            if(!chky) break;
            if(vy[i+1] - vy[i] > w)
                chky = false;
        }
        if(chkx && chky) cout << "YES\n";
        else cout << "NO\n";
    }
    
}
