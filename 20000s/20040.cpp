#include <cstdio>

#define MAX 500002

int root[MAX], rank[MAX];

int _find(int x) {
    if(root[x] == x) return x;
    else return root[x] = _find(root[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if (x == y) return;

    if (rank[x] < rank[y]) root[x] = y;
    else {
        root[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) root[i] = i;
    for(int i=1 ; i<=m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int aa = _find(a);
        int bb = _find(b);
        if(aa == bb) {
            printf("%d", i);
            return 0;
        }
        else {
            _union(a, b);
        }
    }
    puts("0");
    return 0;
}