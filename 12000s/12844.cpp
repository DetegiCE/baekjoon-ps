#include<bits/stdc++.h>
using namespace std;

int n, q;
int tst;
int inp[500003];
int tree[1500003], lazy[1500003];

int init(int node, int st, int en) {
    if(st == en) return tree[node] = inp[st];
    else return tree[node] = init(node*2, st, (st+en)/2) ^ init(node*2+1, (st+en)/2+1, en);
}

void xolor(int node, int st, int en, int lef, int rig, int val) {
    if(lazy[node] != 0) {
        tree[node] ^= ((en-st+1)%2) * lazy[node];
        if(st != en) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(lef > en || rig < st) return;
    if(lef <= st && en <= rig) {
        tree[node] ^= ((en-st+1)%2) * val;
        if(st != en) {
            lazy[node*2] ^= val;
            lazy[node*2+1] ^= val;
        }
        return;
    }
    xolor(node*2, st, (st+en)/2, lef, rig, val);
    xolor(node*2+1, (st+en)/2+1, en, lef, rig, val);
    
    tree[node] = tree[node*2] ^ tree[node*2+1];
    return;
}

int getXolor(int node, int st, int en, int lef, int rig) {
    if(lazy[node] != 0) {
        tree[node] ^= ((en-st+1)%2) * lazy[node];
        if(st != en) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(lef > en || rig < st) return 0;
    if(lef <= st && en <= rig) return tree[node];
    return getXolor(node*2, st, (st+en)/2, lef, rig) ^ getXolor(node*2+1, (st+en)/2+1, en, lef, rig);
}

int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++) {
        scanf("%d", &inp[i]);
    }
    init(1, 1, n);
    for(int i=tst-1 ; i>=1 ; i--) {
        tree[i] = tree[i*2] ^ tree[i*2+1];
    }
    scanf("%d", &q);
    while(q--) {
        int comm, x, y, z;
        scanf(" %d %d %d", &comm, &x, &y);
        x++;
        y++;
        if(x>y) {
            int t = x;
            x = y;
            y = t;
        }
        if(comm == 1) {
            scanf("%d", &z);
            xolor(1, 1, n, x, y, z);
        }
        else {
            int cval = getXolor(1, 1, n, x, y);
            printf("%d\n", cval);
        }
    }
}