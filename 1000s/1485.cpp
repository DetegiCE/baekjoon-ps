#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll dist(pll a, pll b) {
    return abs(a.first-b.first)*abs(a.first-b.first) + abs(a.second-b.second)*abs(a.second-b.second);
}

bool square(pll a, pll b, pll c, pll d) {
    vector<ll> v;
    v.push_back(dist(a, b));
    v.push_back(dist(a, c));
    v.push_back(dist(a, d));
    v.push_back(dist(b, c));
    v.push_back(dist(b, d));
    v.push_back(dist(d, c));
    sort(v.begin(), v.end());
    if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]) return true;
    else return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        pll a[4];
        for(int i=0 ; i<4 ; i++) {
            ll x, y;
            scanf("%lld %lld", &a[i].first, &a[i].second);
        }
        if(square(a[0], a[1], a[2], a[3])) puts("1");
        else puts("0");
    }
}