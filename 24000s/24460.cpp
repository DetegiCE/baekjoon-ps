#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int n;
int a[1030][1030];

int f(int y, int x, int s) {
    vector<int> v;
    if(s == 1) {
        return a[y][x];
    }
    v.PB(f(y,x,s/2));
    v.PB(f(y-s/2,x,s/2));
    v.PB(f(y,x-s/2,s/2));
    v.PB(f(y-s/2,x-s/2,s/2));
    sort(v.begin(), v.end());
    return v[1];
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> a[i][j];
        }
    }
    cout << f(n,n,n);
}