#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<double> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) {
        double t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    double s = 0, u = 0;
    for(int i=k ; i<n-k ; i++) {
        s += v[i];
    }
    
    cout << fixed;
    cout.precision(2);
    cout << (s / (n-2*k)) + 0.00000001 << '\n';
    for(int i=0 ; i<k ; i++) {
        u += v[k];
        u += v[n-k-1];
    }
    for(int i=k ; i<n-k ; i++) u += v[i];
    cout << (u / n) + 0.00000001;
}
