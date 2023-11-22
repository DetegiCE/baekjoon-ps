#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> v;
        for(int i=0 ; i<k ; i++) {
            v.push_back(1);
        }
        for(int i=k ; i<n ; i++) {
            v.push_back(0);
        }
        cout << "The bit patterns are\n";
        do {
            for(int i: v) {
                cout << i;
            }
            cout << '\n';
        } while(prev_permutation(v.begin(), v.end()));
        cout << '\n';
    }
}
