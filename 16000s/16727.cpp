#include<cstdio>

int main()
{
    int a1, a2, b1, b2;
    scanf("%d %d", &a1, &a2);
    scanf("%d %d", &b1, &b2);
    if(a1+b2 > a2+b1) {
        printf("Persepolis");   
    }
    else if(a1+b2 < a2+b1) {
        printf("Esteghlal");   
    }
    else {
        if(a2 > b2) printf("Esteghlal");
        else if(a2 < b2) printf("Persepolis");
        else printf("Penalty");
    }
}
