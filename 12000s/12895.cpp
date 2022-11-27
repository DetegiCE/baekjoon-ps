#include<bits/stdc++.h>
using namespace std;

int n, t, q;
int tst;
int tree[300003], lazy[300003];

int init(int node, int st, int en) {
    if(st == en) return tree[node] = 1;
    else return tree[node] = init(node*2, st, (st+en)/2) | init(node*2+1, (st+en)/2+1, en);
}

void color(int node, int st, int en, int lef, int rig, int val) {
    if(lazy[node] != 0) {
        tree[node] = lazy[node];
        if(st != en) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(lef > en || rig < st) return;
    if(lef <= st && en <= rig) {
        tree[node] = val;
        if(st != en) {
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    color(node*2, st, (st+en)/2, lef, rig, val);
    color(node*2+1, (st+en)/2+1, en, lef, rig, val);
    
    tree[node] = tree[node*2] | tree[node*2+1];
    return;
}

int getColor(int node, int st, int en, int lef, int rig) {
    if(lazy[node] != 0) {
        tree[node] = lazy[node];
        if(st != en) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(lef > en || rig < st) return 0;
    if(lef <= st && en <= rig) return tree[node];
    return getColor(node*2, st, (st+en)/2, lef, rig) | getColor(node*2+1, (st+en)/2+1, en, lef, rig);
}

int main()
{
    scanf("%d %d %d", &n, &t, &q);
    init(1, 1, n);
    while(q--) {
        char comm;
        int x, y, z;
        scanf(" %c %d %d", &comm, &x, &y);
        if(x>y) {
            int t = x;
            x = y;
            y = t;
        }
        if(comm == 'C') {
            scanf("%d", &z);
            color(1, 1, n, x, y, (1<<(z-1)));
        }
        else {
            int cval = getColor(1, 1, n, x, y);
            int ccnt = 0;
            for(int i=0 ; i<31 ; i++) {
                if((cval & (1<<i)) == (1<<i)) ccnt++;
            }
            printf("%d\n", ccnt);
        }
    }
}