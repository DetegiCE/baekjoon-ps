#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
typedef long long ll;

int n;
ll s[12], b[12], difmin = -1;

void f(int idx, ll sour, ll bitt, int cnt) {
    if(idx == n) {
        if(cnt > 0) {
            if(difmin == -1) difmin = abs(sour - bitt);
            else difmin = min(difmin, abs(sour - bitt));
        }
        return;
    }
    f(idx+1, sour, bitt, cnt);
    f(idx+1, sour * s[idx], bitt + b[idx], cnt+1);
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> s[i] >> b[i];
    }
    f(0,1,0,0);
    cout << difmin;
}