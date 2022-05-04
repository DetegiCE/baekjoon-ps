#include<cstdio>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for(int i=-1000 ; i<=1000 ; i++) {
        for(int j=-1000 ; j<=1000 ; j++) {
            if(a*i+b*j==c) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("Not Exist");
    return 0;
}