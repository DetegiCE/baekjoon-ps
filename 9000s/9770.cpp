#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int mx = 1;

int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    while(cin >> t) {
        v.push_back(t);
    }
    
    int vs = v.size();
    for(int i=0 ; i<vs ; i++){
        for(int j=i+1 ; j<vs ; j++) {
            mx = max(mx, gcd(v[i], v[j]));
        }
    }
    cout << mx;
}
