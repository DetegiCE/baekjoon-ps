#include<cstdio>

typedef long long ll;

int n, m;
ll tree[2100000];
ll start;

ll getSum(ll a, ll b) {
    ll sum = 0;
    while (a <= b) {
        if (a & 1) sum += tree[a++];
        if (!(b & 1)) sum += tree[b--];
        a >>= 1;
        b >>= 1;
    }
    return sum;
}

void modify(ll b, ll c) {
    tree[b+start-1] = c;
    int idx = b + start - 1;
    for (int i = idx>>1 ; i >= 1 ; i >>= 1) tree[i] = tree[i<<1] + tree[(i<<1)+1];
}

int main()
{
    scanf("%d %d", &n, &m);
    for(start=1 ; start<n ; start<<=1);
    for(int i=0 ; i<m ; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a == 0) {
            if (b > c) {
                ll t = b;
                b = c;
                c = t;
            }
            printf("%lld\n", getSum(b+start-1, c+start-1));
        }
        else {
            modify(b, c);
        }
    }    
}