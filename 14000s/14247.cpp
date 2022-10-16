#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;
typedef struct tree {
    ll a;
    ll h;
    
    tree(ll a, ll h): a(a), h(h) {}
} TREE;

vector<TREE> v;

bool compare(TREE a, TREE b) {
    return a.h < b.h;
}

int main()
{
    INP;
    
    ll n, s = 0;
    ll a[100001];
    ll h[100001];
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> a[i];
    for(int i=0 ; i<n ; i++) cin >> h[i];
    for(int i=0 ; i<n ; i++) {
        v.emplace_back(a[i], h[i]);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0 ; i<n ; i++) {
        s += v[i].a + (v[i].h * i);
    }
    cout << s;
}
