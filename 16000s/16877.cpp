/*
1 2 3 5 8 13 21
*0
*1 = {*0} = *1
*2 = {*0,*1} = *2
*3 = {*0,*1,*2} = *3
*4 = {*1,*2,*3} = *0
*5 = {*0,*2,*3,*4} = *1
*6 = {*1,*3,*4,*5} = {*0,*1,*3} = *2
*7 = {*2,*4,*5,*6} = {*0,*1,*2} = *3
*8 = {*0,*3,*5,*6,*7} = *1
*9 = {*1,*4,*6,*7,*8} = {*0,*1,*2,*3} = *4
*/

#include<cstdio>

#define MAX(A,B) (A>B?A:B)

int n, pmx;
int p[100001];
int g[3000001];
int fibo[35];

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &p[i]);
        pmx = MAX(pmx, p[i]);
    }
    fibo[1] = 1, fibo[2] = 2;
    g[0]=0, g[1]=1, g[2]=2, g[3]=3, g[4]=0;
    
    for(int i=3 ; i<=33 ; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    bool chk[16];
    for(int i=5 ; i<=pmx ; i++) {
        for(int j=0 ; j<16 ; j++) chk[j] = false;
        for(int j=1 ; j<=33 ; j++) {
            if(fibo[j] <= i) chk[g[i-fibo[j]]] = true;
        }
        for(int j=0 ; j<16 ; j++) {
            if(!chk[j]) {
                g[i] = j;
                break;
            }
        }
    } 
    int ans = 0;
    for(int i=0 ; i<n ; i++) {
        ans ^= g[p[i]];
    }
    printf("%s", ans?"koosaga":"cubelover");
}