#include<cstdio>

#define MIN(A,B) ((A)<(B)?(A):(B))
#define MAX(A,B) ((A)>(B)?(A):(B))

int n, q, st;
int mintree[260000];
int maxtree[260000];

int getMin(int a, int b) {
    int res = mintree[a];
    while (a <= b) {
        if (!(a-b)) {
            res = MIN(res, mintree[a]);
            break;
        }
        if (a & 1) res = MIN(res, mintree[a]), a++;
        if (!(b & 1)) res = MIN(res, mintree[b]), b--;
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int getMax(int a, int b) {
    int res = maxtree[a];
    while (a <= b) {
        if (!(a-b)) {
            res = MAX(res, maxtree[a]);
            break;
        }
        if (a & 1) res = MAX(res, maxtree[a]), a++;
        if (!(b & 1)) res = MAX(res, maxtree[b]), b--;
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for(st=1 ; st<n ; st<<=1);
    for(int i=st ; i<n+st ; i++) {
        scanf("%d", &mintree[i]);
        maxtree[i] = mintree[i];
    }
    for(int i=n+st ; i<2*n+st ; i++) {
        maxtree[i] = 0;
        mintree[i] = 10000001;
    }
    for(int i=st-1 ; i>=1 ; i--) {
        mintree[i] = MIN(mintree[i<<1], mintree[(i<<1)+1]);
        maxtree[i] = MAX(maxtree[i<<1], maxtree[(i<<1)+1]);
    }
    while(q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int minval = getMin(a + st - 1, b + st - 1);
        int maxval = getMax(a + st - 1, b + st - 1);
        printf("%d\n", maxval-minval);
    }
}