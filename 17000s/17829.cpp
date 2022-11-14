#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int a[1026][1026];

void f(int sz) {
    if(sz == 1) return;
    int ip = 0, jp = 0;
    for(int i=0 ; i<sz ; i+=2) {
        jp = 0;
        for(int j=0 ; j<sz ; j+=2) {
            int b[5] = {a[i][j],a[i+1][j],a[i+1][j+1],a[i][j+1]};
            sort(b,b+4);
            a[ip][jp] = b[2];
            jp++;
        }
        ip++;
    }
    f(sz/2);
}

int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> a[i][j];
        }
    }
    f(n);
    cout << a[0][0];
}