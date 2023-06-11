#include<bits/stdc++.h>
using namespace std;

int cnt[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    for(int i=0 ; i<n-1 ; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            if(cnt[b] == 1) cout << "no\n";
            else cout << "yes\n";
        }
        else cout << "yes\n";
    }
}
