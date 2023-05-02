#include<bits/stdc++.h>
using namespace std;
#define ABS(A) (A>0?A:-A)
#define MAX(A,B) (A>B?A:B)
#define ALL(A) A.begin(),A.end()

int n, ans;
vector<int> v, xy, kz;
map<int,int> mp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            int ab = ABS((v[i]-v[j]));
            xy.push_back(v[i]+v[j]);
            kz.push_back(ab);
            if(mp.find(ab) == mp.end()) {
                mp[ab] = MAX(v[i], v[j]);
            }
            else mp[ab] = MAX(mp[ab], MAX(v[i], v[j]));
        }
    }
    
    sort(ALL(xy));
    sort(ALL(kz));
    
    for(auto x: xy) {
        if(binary_search(ALL(kz), x)) {
            ans = MAX(ans, mp[x]);
        }
    }
    
    cout << ans;
}
