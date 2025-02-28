#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b, ans;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for(int i=0 ; i<n ; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    for(int i=0 ; i<=n ; i++) {
        ans.push_back(0);
    }

    int same = 0;
    for(int i=0 ; i<n ; i++) {
        if(a[i] == b[i]) same++;
    }

    for(int i=0 ; i<n ; i++) {
        int lef = i;
        int rig = i;
        int chk = same;
        while(0 <= lef && rig < n) {
            if(a[lef] == b[rig]) chk++;
            if(a[rig] == b[lef]) chk++;
            if(a[lef] == b[lef]) chk--;
            if(a[rig] == b[rig]) chk--;
            ans[chk]++;
            lef--;
            rig++;
        }

        lef = i;
        rig = i+1;
        chk = same;
        while(0 <= lef && rig < n) {
            if(a[lef] == b[rig]) chk++;
            if(a[rig] == b[lef]) chk++;
            if(a[lef] == b[lef]) chk--;
            if(a[rig] == b[rig]) chk--;
            ans[chk]++;
            lef--;
            rig++;
        }
    }

    for(int i: ans) {
        cout << i << '\n';
    }
}