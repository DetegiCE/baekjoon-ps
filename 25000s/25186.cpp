#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[100005];
ll sum, mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> d[i];
        sum += d[i];
        mx = max(mx, d[i]);
    }
    if(sum-mx >= mx || (n==1 && d[0] == 1)) cout << "Happy";
    else cout << "Unhappy";
}
