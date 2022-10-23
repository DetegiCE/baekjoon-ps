#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int days[1000003];
int maxs[1000003];
ll sum;

void sol() {
    cin >> n;
    maxs[n+1] = 0;
    sum = 0;
    for(int i=1 ; i<=n ; i++) cin >> days[i];
    for(int i=n ; i>=1 ; i--) maxs[i] = max(maxs[i+1], days[i]);
    for(int i=1 ; i<=n ; i++) {
        if(days[i] < maxs[i]) sum += maxs[i] - days[i];
    }
    cout << sum << '\n';
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