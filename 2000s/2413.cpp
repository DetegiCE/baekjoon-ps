#include<bits/stdc++.h>
using namespace std;

int n;
int used[50001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        if(used[t] != 0) {
            cout << used[t] << ' ';
            continue;
        }
        if(t > 1 && used[t-1] == 0) {
            cout << t-1 << ' ';
            used[t-1] = t;
            used[t] = t-1;
        }
        else {
            cout << t << ' ';
            used[t] = t;
        }
    }
}
