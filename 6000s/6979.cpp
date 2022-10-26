#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    int x[1002], y[1002];
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> x[i];
    for(int i=0 ; i<n ; i++) cin >> y[i];
    
    int mx = 0;
    int xpos = 0, ypos = 0;
    while(xpos < n && ypos < n) {
        if(y[ypos] >= x[xpos]) {
            if((ypos - xpos) > mx) mx = ypos - xpos;
            ypos++;
        }
        else xpos++;
    }
    cout << "The maximum distance is " << mx << "\n\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}