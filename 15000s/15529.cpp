#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    vector<int> nums;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    
    int mx = -1;
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            int p = nums[i] * nums[j];
            string ps = to_string(p);
            bool flag = true;
            for(int k=1 ; k<ps.length() ; k++) {
                if(ps[k]-48 != ps[k-1]-47) {
                    flag = false;
                }
            }
            if(flag) {
                mx = max(mx, p);
            }
        }
    }
    
    cout << mx;
    
}
