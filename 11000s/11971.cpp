#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    int road[101];
    cin >> n >> m;
    int lc = 0;
    for(int i=0 ; i<n ; i++) {
        int l, s;
        cin >> l >> s;
        for(int j=lc ; j<lc+l ; j++) {
            road[j] = s;   
        }
        lc += l;
    }
    lc = 0;
    for(int i=0 ; i<m ; i++) {
        int l, s;
        cin >> l >> s;
        for(int j=lc ; j<lc+l ; j++) {
            road[j] -= s;
        }
        lc += l;
    }
    int mx = 0;
    for(int i=0 ; i<100 ; i++) {
        if(road[i] < 0) {
            mx = max(mx, -road[i]);
        }
    }
    cout << mx; 
}
