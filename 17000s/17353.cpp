#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int n, siz;
vector<ll> dat, lzy, cnt;

void propagate(int l, int r, int pos) {
    // cout << "prop(" << l << ' ' << r << ' ' << pos << ")\n";
    if(lzy[pos]) {
        if(l != r) {
            lzy[pos*2] += lzy[pos];
            lzy[pos*2+1] += lzy[pos];
            cnt[pos*2] += cnt[pos];
            cnt[pos*2+1] += cnt[pos];
        }
        else {
            dat[pos] += cnt[pos]*(pos-siz+2)-lzy[pos];
        }
        lzy[pos] = 0;
        cnt[pos] = 0;
    }
}

void update(int l, int r, int a, int b, int pos) {
    // cout << "update(" << l << ' ' << r << ' ' << a << ' ' << b << ' ' << pos << ")\n";
    propagate(l, r, pos);
    if(a <= l && r <= b) {
        lzy[pos] += (a+1);
        cnt[pos] ++;
        propagate(l, r, pos);
        return;
    }
    if(b < l || r < a) return;
    update(l, (l+r)/2, a, b, pos*2);
    update((l+r)/2+1, r, a, b, pos*2+1);

}

ll getSum(int l, int r, int a, int pos) {
    propagate(l, r, pos);
    if(a <= l && r <= a) return dat[pos];
    if(a < l || r < a) return 0;
    return getSum(l, (l+r)/2, a, pos*2) + getSum((l+r)/2+1, r, a, pos*2+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(siz=1 ; siz<n ; siz<<=1);
    dat.resize(siz*2);
    lzy.resize(siz*2);
    cnt.resize(siz*2);
    for(int i=0 ; i<n ; i++) {
        cin >> dat[i+siz];
    }

    int q;
    cin >> q;
    while(q--) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            int l, r;
            cin >> l >> r;
            update(0, siz-1, l-1, r-1, 1);
        }
        else {
            int x;
            cin >> x;
            cout << getSum(0, siz-1, x-1, 1) << '\n';
        }
        // for(int i=1 ; i<siz*2 ; i++) cout << dat[i] << ' '; cout << '\n';
        // for(int i=1 ; i<siz*2 ; i++) cout << lzy[i] << ' '; cout << '\n';
        // for(int i=1 ; i<siz*2 ; i++) cout << cnt[i] << ' '; cout << '\n';
    }
}