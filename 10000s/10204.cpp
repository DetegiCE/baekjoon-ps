#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 98765432

int n;
int dst[103][103];

void floyd() {
    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
}

void sol() {
    int r;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            dst[i][j] = INF;
        }
        dst[i][i] = 0;
    }
    cin >> r;
    for(int i=0 ; i<r ; i++) {
        string a, b;
        int ia, ib;
        cin >> a >> b;
        a = a.substr(1, a.length()-1);
        b = b.substr(1, b.length()-1);
        ia = stoi(a);
        ib = stoi(b);
        dst[ia][ib] = dst[ib][ia] = 1;
    }
    floyd();
    string st;
    int ist;
    cin >> st;
    st = st.substr(1, st.length()-1);
    ist = stoi(st);
    
    int cnt = 0;
    for(int i=1 ; i<=n ; i++) {
        if(i == ist) continue;
        if(dst[ist][i] <= 2) cnt++;
    }
    cout << "The number of supervillains in 2-hop neighborhood of v";
    cout << st << " is " << cnt << '\n';
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