#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
int a[1003], b[1003], ca[1003], cb[1003];
map<int, ll> asum;
map<int, ll> bsum;

int main()
{
    INP;
    
    ll t, cnt = 0;
    cin >> t;
    
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    cin >> m;
    for(int i=1 ; i<=m ; i++) cin >> b[i];
    for(int i=1 ; i<=n ; i++) ca[i] = ca[i-1] + a[i];
    for(int i=1 ; i<=m ; i++) cb[i] = cb[i-1] + b[i];
    for(int i=1 ; i<=n ; i++) {
        for(int j=i ; j<=n ; j++) {
            asum[ca[j]-ca[i-1]] += 1;
        }
    }
    for(int i=1 ; i<=m ; i++) {
        for(int j=i ; j<=m ; j++) {
            bsum[cb[j]-cb[i-1]] += 1;
        }
    }
    for(auto i: asum) {
        auto j = bsum.find(t-i.first);
        if(j != bsum.end()) {
            cnt += (i.second) * (j->second);
        }
    }
    cout << cnt;
}