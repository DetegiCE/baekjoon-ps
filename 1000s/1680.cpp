#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol() {
    ll W, N, x[1001], w[1001], tot = 0, cur = 0;
    cin >> W >> N;
    for(int i=0 ; i<N ; i++) {
        cin >> x[i] >> w[i];
    }
    for(int i=0 ; i<N ; i++) {
        if(cur + w[i] > W) {
            tot += x[i] * 2;
            cur = w[i];
        }
        else if(cur + w[i] == W) {
            if(i == N-1) {
                break;
            }
            tot += x[i] * 2;
            cur = 0;
        }
        else {
            cur += w[i];
        }
    }
    cout << tot + x[N-1] * 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}