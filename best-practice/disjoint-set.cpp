#include <cstdio>

#define MAX 100

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
    for(int i=0 ; i<MAX ; i++) root[i] = i;
}