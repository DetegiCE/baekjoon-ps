#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

ll n, b, c;
ll a[1000006];
ll cost;

int main()
{
    INP;
    
    cin >> n >> b >> c;
    if(c > b) c = b;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];   
    }
    for(int i=0 ; i<n ; i++) {
        if(a[i] == 0) continue;
        if(a[i+1] > a[i+2]) {
            ll mnv = min(a[i], a[i+1]-a[i+2]);
            cost += mnv * (b+c);
            a[i] -= mnv;
            a[i+1] -= mnv;
            
            mnv = min(a[i], min(a[i+1], a[i+2]));
            cost += mnv * (b+c*2);
            a[i] -= mnv;
            a[i+1] -= mnv;
            a[i+2] -= mnv;
        }
        else {
            ll mnv = min(a[i], min(a[i+1], a[i+2]));
            cost += mnv * (b+c*2);
            a[i] -= mnv;
            a[i+1] -= mnv;
            a[i+2] -= mnv;
            
            mnv = min(a[i], a[i+1]);
            cost += mnv * (b+c);
            a[i] -= mnv;
            a[i+1] -= mnv;
        }
        cost += b * a[i];
        a[i] = 0;
    }
    cout << cost;
}