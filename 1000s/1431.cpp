#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

int n;
vector<string> v;

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        int as = 0, bs = 0;
        for(int i=0 ; i<a.length() ; i++) {
            if(a[i] < 'A') as += a[i] - 48;
            if(b[i] < 'A') bs += b[i] - 48;
        }
        if(as == bs) {
            return a < b;
        }
        return as < bs;
    }
    return a.length() < b.length();
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        string t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0 ; i<n ; i++) {
        cout << v[i] << '\n';
    }
    
}