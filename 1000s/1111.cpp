#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    if(n == 1) {
        cout << "A";
        return 0;
    }
    if(n == 2) {
        if(v[0] == v[1]) {
            cout << v[0];
        }
        else {
            cout << "A";
        }
        return 0;
    }
    
    int a = 0;
    int dif = 0;
    for(int i=1 ; i<n ; i++) {
        if(v[i-1] == v[i]) dif++;
    }
    if(dif == n-1) {
        cout << v[0];
        return 0;
    }
    
    int dif2 = 0;
    for(int i=2 ; i<n ; i++) {
        if(v[i-1] == v[i]) dif2++;
    }
    if(dif2 == n-2) {
        cout << v[1];
        return 0;
    }
    
    if(dif != 0 || dif2 != 0) {
        cout << "B";
        return 0;
    }
    
    for(int i=1 ; i<n-1 ; i++) {
        if((v[i+1]-v[i]) % (v[i]-v[i-1]) == 0) {
            if(i == 1) {
                a = (v[i+1] - v[i]) / (v[i] - v[i-1]);
            }   
            else {
                if(a != (v[i+1] - v[i]) / (v[i] - v[i-1])) {
                    cout << "B";
                    return 0;
                }
            }
        }
        else {
            cout << "B";
            return 0;
        }
    }
    
    int b = 0;
    for(int i=1 ; i<n ; i++) {
        if(i == 1) {
            b = v[i] - a*v[i-1];
        }
        else {
            if(b != (v[i]-a*v[i-1])) {
                cout << "B";
                return 0;
            }
        }
    }
    
    cout << a*v[n-1]+b;
    
}
