#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

int n;
int root[1000006];
int cnt[1000006];

int _find(int x) {
    if(root[x] == x) return x;
    else return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if(x == y) return;
    root[y] = x;
    cnt[x] += cnt[y];
}

int main()
{
    INP;
    
    cin >> n;
    for(int i=1 ; i<=1000000 ; i++) root[i] = i, cnt[i] = 1;
    for(int i=0 ; i<n ; i++) {
        char comm;
        int a, b;
        cin >> comm >> a;
        if(comm == 'I') {
            cin >> b;
            _union(a, b);
        }
        else {
            cout << cnt[_find(a)] << '\n';
        }
        
    }
}