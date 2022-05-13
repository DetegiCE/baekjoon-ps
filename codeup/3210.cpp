#include<cstdio>

int tree[140000];
int st, n, m;

int getmax(int left, int right) {
    int curmx = tree[left];
    while(left <= right) {
        if(left == right) return curmx = curmx>tree[left]?curmx:tree[left];
        if(left % 2 == 1) {
            curmx = curmx>tree[left]?curmx:tree[left];
            left++;
        }
        if(right % 2 == 0) {
            curmx = curmx>tree[right]?curmx:tree[right];
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return curmx;
}

int main()
{
    scanf("%d", &n);
    for(st=1 ; st<n ; st*=2);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &tree[st+i]);
    }
    for(int i=st-1 ; i>=1 ; i--) {
        tree[i] = tree[i*2]>tree[i*2+1]?tree[i*2]:tree[i*2+1];
    }
    scanf("%d", &m);
    for(int i=0 ; i<m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d ", getmax(a+st-1, b+st-1));
    }
}