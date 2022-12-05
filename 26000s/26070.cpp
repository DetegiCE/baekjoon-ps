#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

ll a, b, c, x, y, z;
ll cnt = 0;

void f() {
    ll amov = x/3;
    ll bmov = y/3;
    ll cmov = z/3;
    y += amov;
    z += bmov;
    x += cmov;
    x -= amov*3;
    y -= bmov*3;
    z -= cmov*3;
}

void calc() {
    ll a1 = min(a, x);
    ll b1 = min(b, y);
    ll c1 = min(c, z);
    a -= a1, x -= a1;
    b -= b1, y -= b1;
    c -= c1, z -= c1;
    cnt += (a1 + b1 + c1);
}

int main()
{
    INP;
    cin >> a >> b >> c >> x >> y >> z;
    
    calc();
    f();
    calc();
    f();
    calc();
    
    cout << cnt;
}