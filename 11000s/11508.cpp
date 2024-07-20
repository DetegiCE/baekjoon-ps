#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> c;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        c.push_back(t);
    }
    sort(c.begin(), c.end(), greater<int>());
    int s = 0;
    for(int i=0 ; i<n ; i++) {
        if(i % 3 == 2) continue;
        s += c[i];
    }
    cout << s;
}