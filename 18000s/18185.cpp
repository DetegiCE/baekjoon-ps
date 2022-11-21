#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

ll n;
ll a[10004];
ll cost;

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];   
    }
    for(int i=0 ; i<n ; i++) {
        if(a[i] == 0) continue;
        if(a[i+1] > a[i+2]) {
            ll mnv = min(a[i], a[i+1]-a[i+2]);
            cost += mnv * 5;
            a[i] -= mnv;
            a[i+1] -= mnv;
            
            mnv = min(a[i], min(a[i+1], a[i+2]));
            cost += mnv * 7;
            a[i] -= mnv;
            a[i+1] -= mnv;
            a[i+2] -= mnv;
        }
        else {
            ll mnv = min(a[i], min(a[i+1], a[i+2]));
            cost += mnv * 7;
            a[i] -= mnv;
            a[i+1] -= mnv;
            a[i+2] -= mnv;
            
            mnv = min(a[i], a[i+1]);
            cost += mnv * 5;
            a[i] -= mnv;
            a[i+1] -= mnv;
        }
        cost += 3 * a[i];
        a[i] = 0;
    }
    cout << cost;
}