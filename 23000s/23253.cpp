#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)
typedef long long ll;

int main()
{
    INP;
    
    int m, n;
    cin >> m >> n;
    for(int i=0 ; i<n ; i++) {
        int k, bef, aft;
        cin >> k >> bef;
        for(int j=1 ; j<k ; j++) {
            cin >> aft;
            if(bef < aft) {
                cout << "No";
                return 0;
            }
            bef = aft;
        }
    }
    cout << "Yes";
}