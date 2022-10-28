#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, tot;
vector<ll> v;
vector<ll> sums;
ll a[103];

void remove_num(ll num) {
    auto pos = lower_bound(sums.begin(), sums.end(), num);
    sums.erase(pos);
}

void insert_num(ll num) {
    sums.push_back(num);
}

void go(int t) {
    if(t == n) {
        sort(a, a+n);
        for(int i=0 ; i<n ; i++) {
            if(a[i] < -100000000 || a[i] > 100000000) {
                cout << "Impossible";
                exit(0);
            }
        }
        for(int i=0 ; i<n ; i++) {
            cout << a[i] << ' ';
        }
        exit(0);
    }
    ll curv = sums[0] - a[0];
    ll flg = 0;
    for(ll i=0 ; i<t ; i++) {
        if(binary_search(sums.begin(), sums.end(), curv + a[i])) {
            flg++;
        }
        else break;
    }
    if(flg == t) {
        for(ll i=0 ; i<t ; i++) {
            remove_num(curv + a[i]);
        }
        a[t] = curv;
        go(t+1);
        for(int i=0 ; i<t ; i++) {
            insert_num(curv + a[i]);
        }
        a[t] = 0;
        sort(sums.begin(), sums.end());
    }
    else if(t > 4) {
        cout << "Impossible";
        exit(0);
    }
    else return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll tsum = 0;
    cin >> n;
    tot = n * (n-1) / 2;
    for(ll i=0 ; i<tot ; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
        sums.push_back(t);
        tsum += t;
    }
    if(tsum % (n-1) != 0) {
        cout << "Impossible";
        return 0;
    }
    if(n == 2) {
        cout << (v[0]-2)/2 << ' ' << v[0] - (v[0]-2)/2;
        return 0;
    }
    sort(v.begin(), v.end());
    sort(sums.begin(), sums.end());
    for(ll i=2 ; i<tot ; i++) {
        if((v[0]+v[1]+v[i]) % 2 == 0) {
            a[0] = (v[0]+v[1]+v[i])/2 - v[i];
            a[1] = (v[0]+v[1]+v[i])/2 - v[1];
            a[2] = (v[0]+v[1]+v[i])/2 - v[0];
            remove_num(v[0]);
            remove_num(v[1]);
            remove_num(v[i]);
            go(3);
            insert_num(v[0]);
            insert_num(v[1]);
            insert_num(v[i]);
            sort(sums.begin(), sums.end());
        } 
    }
    cout << "Impossible";
}