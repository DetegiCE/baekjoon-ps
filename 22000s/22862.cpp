#include<bits/stdc++.h>
using namespace std;

int a[1000002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    int lpos = 1, rpos = 1;
    int ocnt = a[1]%2;
    int ecnt = 1-ocnt;
    int mxv = ecnt;
    while(lpos <= rpos) {
        if(rpos == n) break;
        if(ocnt < k) {
            rpos++;
            if(a[rpos] % 2 == 0) {
                ecnt++;
                mxv = max(mxv, ecnt);
            }
            else {
                ocnt++;
            }
        }
        else {
            if(rpos + 1 <= n && a[rpos+1] % 2 == 0) {
                rpos++;
                ecnt++;
                mxv = max(mxv, ecnt);
            }
            else {
                if(a[lpos] % 2 == 0) {
                    ecnt--;
                }
                else {
                    ocnt--;
                }
                lpos++;
            }
        }
    }
    cout << mxv;
}
