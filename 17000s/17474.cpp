#include<cstdio>
typedef long long ll;
#define MAX(A,B) (A>B?A:B)
#define MIN(A,B) (A>B?B:A)
#define LN(x) (x*2)
#define RN(x) (x*2+1)

struct NODE {
    int max1, max2, cntmax;
    ll sum;
};

int n, m;
NODE tree[4000004];
int val[1000001];

void merge(int i) {
    if(tree[LN(i)].max1 == tree[RN(i)].max1) {
        tree[i].max1 = tree[LN(i)].max1;
        tree[i].max2 = MAX(tree[LN(i)].max2, tree[RN(i)].max2);
        tree[i].cntmax = tree[LN(i)].cntmax + tree[RN(i)].cntmax;
    }
    else {
        tree[i].max1 = MAX(tree[LN(i)].max1, tree[RN(i)].max1);
        tree[i].max2 = MAX(MIN(tree[LN(i)].max1, tree[RN(i)].max1), MAX(tree[LN(i)].max2, tree[RN(i)].max2));
        tree[i].cntmax = (tree[LN(i)].max1 > tree[RN(i)].max1 ? tree[LN(i)].cntmax : tree[RN(i)].cntmax);
    }
    tree[i].sum = tree[LN(i)].sum + tree[RN(i)].sum;
}

void treeBuild(int node, int s, int e) {
    if(s == e) {
        tree[node].max1 = val[s];
        tree[node].max2 = -1;
        tree[node].cntmax = 1;
        tree[node].sum = val[s];
    }
    else {
        int mid = (s+e)/2;
        treeBuild(LN(node), s, mid);
        treeBuild(RN(node), mid+1, e);
        merge(node);
    }
}

void lazy_update(int node, int s, int e) {
    if(s != e) {
        if(tree[node].max1 < tree[LN(node)].max1) {
            tree[LN(node)].sum -= 1ll * tree[LN(node)].cntmax * (tree[LN(node)].max1 - tree[node].max1);
            tree[LN(node)].max1 = tree[node].max1;
        }
        if(tree[node].max1 < tree[RN(node)].max1) {
            tree[RN(node)].sum -= 1ll * tree[RN(node)].cntmax * (tree[RN(node)].max1 - tree[node].max1);
            tree[RN(node)].max1 = tree[node].max1;
        }
    }
}

void update(int node, int s, int e, int l, int r, int val) {
    int mid = (s+e)/2;
    if(e < l || r < s || tree[node].max1 <= val) return;
    lazy_update(node, s, e);
    if(l <= s && e <= r && tree[node].max2 < val) {
        tree[node].sum -= 1ll * tree[node].cntmax * (tree[node].max1 - val);
        tree[node].max1 = val;
        lazy_update(node, s, e);
        return;
    }
    update(LN(node), s, mid, l, r, val);
    update(RN(node), mid+1, e, l, r, val);
    merge(node);
}

ll findMax(int node, int s, int e, int l, int r) {
    int mid = (s + e) / 2;
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[node].max1;
    lazy_update(node, s, e);
    ll lmax = findMax(LN(node), s, mid, l, r);
    ll rmax = findMax(RN(node), mid+1, e, l, r);
    return MAX(lmax, rmax);
}

ll findSum(int node, int s, int e, int l, int r) {
    int mid = (s + e) / 2;
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[node].sum;
    lazy_update(node, s, e);
    ll lsum = findSum(LN(node), s, mid, l, r);
    ll rsum = findSum(RN(node), mid+1, e, l, r);
    return lsum + rsum;
}

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &val[i]);
    }
    treeBuild(1, 1, n);
    scanf("%d", &m);
    while(m--) {
        int ord, l, r, x;
        scanf("%d %d %d", &ord, &l, &r);
        if(ord == 1) {
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
        }
        if(ord == 2) {
            printf("%lld\n", findMax(1, 1, n, l, r));
        }
        if(ord == 3) {
            printf("%lld\n", findSum(1, 1, n, l, r));
        }
    }
}