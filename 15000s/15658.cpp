#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int op[5];
int mx = -2e9;
int mn = 2e9;

void f(int pos, int val) {
    if(pos == n) {
        mx = max(mx, val);
        mn = min(mn, val);
        return;
    }
    for(int i=1 ; i<=4 ; i++) {
        if(op[i] > 0) {
            op[i]--;
            if(i == 1) {
                f(pos+1, val+a[pos]);
            }
            else if(i == 2) {
                f(pos+1, val-a[pos]);
            }
            else if(i == 3) {
                f(pos+1, val*a[pos]);
            }
            else {
                f(pos+1, val/a[pos]);
            }
            op[i]++;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    for(int i=1 ; i<=4 ; i++) {
        scanf("%d", &op[i]);
    }
    f(1, a[0]);
    printf("%d\n%d", mx, mn);
}