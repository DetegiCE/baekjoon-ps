#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> v;
vector<int> ans;

int main()
{
    INP;
    int n;
    while(cin >> n) {
        v.clear();
        int a[100003], lislen[100003];
        for(int i=0 ; i<n ; i++) {
            cin >> a[i];
        }
        v.push_back(-1000000);
        for(int i=0 ; i<n ; i++) {
            if(a[i] > v.back()) {
                v.push_back(a[i]);
                lislen[i] = v.size() - 1;
            }
            else {
                int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                v[idx] = a[i];
                lislen[i] = idx;
            }
        }
        cout << v.size() - 1 << '\n';
    }
}