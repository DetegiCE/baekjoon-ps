#include<cstdio>

int main()
{
    int count = 6;
    for(int i=0 ; i<6 ; i++) {
        char a;
        scanf(" %c", &a);
        if(a == 'W') {
            count--;
        }
    }
    printf("%d", count/2+1==4?-1:count/2+1);
}
