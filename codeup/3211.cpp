#include<cstdio>

#define MIN(A,B) ((A)>(B)?(B):(A))
#define MAX(A,B) ((A)>(B)?(A):(B))

typedef long long ll;

int n, m, st;
int mintree[140000], maxtree[140000];

int getmin(int left, int right) {
    int minv = 1000001;
    while(left <= right) {
        if(left == right) return minv = MIN(minv, mintree[left]);
        if(left % 2 == 1) minv = MIN(minv, mintree[left]), left++;
        if(right % 2 == 0) minv = MIN(minv, mintree[right]), right--;
        left /= 2;
        right /= 2;
    }
    return minv;
}

int getmax(int left, int right) {
    int maxv = 0;
    while(left <= right) {
        if(left == right) return maxv = MAX(maxv, maxtree[left]);
        if(left % 2 == 1) maxv = MAX(maxv, maxtree[left]), left++;
        if(right % 2 == 0) maxv = MAX(maxv, maxtree[right]), right--;
        left /= 2;
        right /= 2;
    }
    return maxv;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(st=1 ; st<n ; st*=2);
    for(int i=st ; i<st+n ; i++) {
        scanf("%d", &mintree[i]);
        maxtree[i] = mintree[i];
    }
    for(int i=st+n ; i<st*2 ; i++) {
        mintree[i] = 1000001;
        maxtree[i] = 0;
    }
    for(int i=st-1 ; i>=1 ; i--) {
        mintree[i] = MIN(mintree[i*2], mintree[i*2+1]);
        maxtree[i] = MAX(maxtree[i*2], maxtree[i*2+1]);
    }
    for(int i=0 ; i<m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == b) puts("0");
        else {
            int minv = getmin(a+st-1, b+st-1);
            int maxv = getmax(a+st-1, b+st-1);
            printf("%d\n", maxv, minv, maxv-minv);
        }
    }
}