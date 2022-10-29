#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 98765432

int m;
int dst[33][33];

void floyd() {
    for(int k=1 ; k<=m ; k++) {
        for(int i=1 ; i<=m ; i++) {
            for(int j=1 ; j<=m ; j++) {
                if(dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
}

void sol() {
    int n, p;
    map<string, int> mp;
    cin >> m >> n >> p;
    for(int i=1 ; i<=m ; i++) {
        for(int j=1 ; j<=m ; j++) {
            dst[i][j] = INF;
        }
    }
    for(int i=1 ; i<=m ; i++) {
        string s;
        cin >> s;
        mp.insert({s, i});
    }
    for(int i=0 ; i<n ; i++) {
        string a, b;
        cin >> a >> b;
        int aid, bid;
        aid = mp.find(a)->second;
        bid = mp.find(b)->second;
        dst[aid][bid] = 1;
        dst[bid][aid] = 1;
    }
    floyd();
    
    for(int i=0 ; i<p ; i++) {
        int pr;
        string a, b;
        cin >> pr >> a >> b;
        int aid = mp.find(a)->second;
        int bid = mp.find(b)->second;
        if(dst[aid][bid] == INF) cout << "NO SHIPMENT POSSIBLE\n";
        else {
            cout << "$" << dst[aid][bid] * pr << "00\n";
        }
    }
    cout << "\n";
}

int main()
{
    INP;
    
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        cout << "DATA SET " << i << "\n\n";
        sol();
    }
}