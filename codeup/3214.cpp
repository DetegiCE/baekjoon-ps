#include<cstdio>

typedef long long ll;

ll n, st, m, k;
ll tree[270000];

void modify(int idx, int val) {
    tree[idx] = val;
    do {
        idx /= 2;
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    } while(idx > 1);
}

ll getsum(int st, int en) {
    ll res = 0;
    while(st <= en) {
        if(st % 2 == 1) res += tree[st++];
        if(en % 2 == 0) res += tree[en--];
        st /= 2;
        en /= 2;
    }
    return res;
}

int main()
{
    scanf("%lld", &n);
    for(st=1 ; st<n ; st*=2);
    for(int i=0 ; i<n ; i++) {
        scanf("%lld", &tree[st+i]);
    }
    for(int i=st-1 ; i>=1 ; i--) {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    scanf("%lld %lld", &m, &k);
    for(int i=0 ; i<m+k ; i++) {
        ll x, a, b;
        scanf("%lld %lld %lld", &x, &a, &b);
        if(x == 0) {
            modify(a+st-1, b);
        }
        else {
            printf("%lld\n", getsum(a+st-1, b+st-1));
        }
    }
}