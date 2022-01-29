#include<cstdio>

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i=l ; i<=100 ; i++) {
        //printf("%d\n", i);
        if(i == 2) {
            if(n % 2 == 0) continue;
            else {
                printf("%d %d", n/2, n/2+1);
                return 0;
            }
        }
        if(i % 2 == 1) {
            if(n % i == 0) {
                int center = n / i;
                if(center-i/2 < 0) {
                    printf("-1");
                    return 0;
                }
                else {
                    for(int j=center-i/2 ; j<=center+i/2 ; j++) {
                        printf("%d ", j);
                    }
                    return 0;
                }
            }
            else continue;
        }
        else {
            if(n % (i/2) == 0 && (n / (i/2)) % 2 == 1) {
                int center1 = (n/(i/2))/2;
                int center2 = (n/(i/2))/2+1;
                int left = center2 - i/2;
                if(left < 0) {
                    printf("-1");
                    return 0;
                }
                else {
                    for(int j=left ; j<=center1+i/2 ; j++) {
                        printf("%d ", j);
                    }
                    return 0;
                }
            }
            else continue;
        }
    }
    printf("-1");
}
