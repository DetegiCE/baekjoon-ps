#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define MP(A,B) make_pair(A,B)
#define MOD 987654321
typedef long long ll;

int tree[4200000];
int tst = 2097152;

void upd(int pos, int val) {
    while(pos >= 1) {
        tree[pos] += val;
        pos /= 2;
    }
}

int _find(int pos) {
    int st = 0;
    int cur = 1;
    while(cur < tst) {
        if(pos > tree[cur*2] + st) {
            st += tree[cur * 2];
            cur = cur * 2 + 1;
        }
        else {
            cur = cur * 2;
        }
    }
    upd(cur, -1);
    return cur - tst + 1;
}

int main() 
{
    INP;
    
    int n;
    cin >> n;
    while(n--) {
        int a, s;
        cin >> a >> s;
        if(a == 1) {
            upd(s+tst-1, 1);
        }
        else {
            cout << _find(s) << '\n';
        }
    }
}