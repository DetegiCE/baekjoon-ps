#include<cstdio>
#include<cmath>

int n, x[101], y[101];
int mx, mx1, mx2;

int dist(int a, int b) {
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=i ; j<n ; j++) {
            if(dist(i, j) > mx) {
                mx = dist(i, j);
                mx1 = i;
                mx2 = j;
            }
        }
    }
    printf("%.2f\n", sqrt(mx));
    if(x[mx1] < x[mx2] || (x[mx1] == x[mx2] && y[mx1] < y[mx2])) {
        int t = mx1;
        mx1 = mx2;
        mx2 = t;
    }
    printf("(%d,%d)\n",x[mx1],y[mx1]);
    printf("(%d,%d)",x[mx2],y[mx2]);
}