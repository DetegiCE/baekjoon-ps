#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

void sol(int cnt) {
    int a;
    cin >> a;
    
    bool check[10];
    int ccnt = 0;
    
    if(a == 0) {
        cout << "Case #" << cnt << ": INSOMNIA\n";
        return;
    }
    for(int i=0 ; i<10 ; i++) check[i] = false;
    for(int i=1 ;; i++) {
        int c = i * a;
        while(c > 0) {
            if(!check[c%10]) {
                check[c%10] = true;
                ccnt++;
            }
            c /= 10;
            if(ccnt >= 10) {
                cout << "Case #" << cnt << ": " << (i*a) << '\n';
                return;
            }
        }
    }
}

int main()
{
    INP;
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        sol(i);
    }
}
