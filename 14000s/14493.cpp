#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;
int a[50001];
int b[50001];

int main()
{
    INP;
    int n, t = 0, i=1;
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> a[i] >> b[i];
    t = b[0];
    while(i < n) {
        t++;
        if(t%(a[i]+b[i])<b[i]) {
            t+=(b[i]-t%(a[i]+b[i])-1);
        }
        else i++;
    }
    cout << t + 1;
}
