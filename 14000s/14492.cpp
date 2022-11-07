#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

int main()
{
    INP;
    int n;
    int a[303][303], b[303][303], cnt = 0;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> b[i][j];
        }
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            int s = 0;
            for(int k=1 ; k<=n ; k++) {
                s += a[i][k] * b[k][j];
            }
            cnt += s>0;
        }
    }
    cout << cnt;
}
