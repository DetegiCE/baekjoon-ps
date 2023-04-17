#include<bits/stdc++.h>
using namespace std;

int n, f;
vector<int> v;
int mul[11][11];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> f;
    
    for(int i=1 ; i<=n ; i++) {
        v.push_back(i);
    }
    
    mul[0][0] = 1;
    for(int i=1 ; i<n ; i++) {
        mul[i][0] = mul[i][i] = 1;
        for(int j=1 ; j<i ; j++) {
            mul[i][j] = mul[i-1][j] + mul[i-1][j-1];
        }
    }
    
    do {
        int s = 0;
        for(int i=0 ; i<n ; i++) {
            s += v[i] * mul[n-1][i];
        }
        if(s == f) {
            for(int i=0 ; i<n ; i++) {
                cout << v[i] << ' ';
            }
            break;
        }
    } while(next_permutation(v.begin(), v.end()));
}
