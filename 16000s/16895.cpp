#include<cstdio>

int main()
{
    int n, p[1001], cnt = 0;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &p[i]);
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=1 ; j<=p[i] ; j++) {
            int g = 0;
            for(int k=0 ; k<n ; k++) {
                if(i == k) g ^= p[k] - j;
                else g ^= p[k];
            }
            if(g == 0) cnt++;
        }
    }
    printf("%d", cnt);
}