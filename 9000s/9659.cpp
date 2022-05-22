/*
*0
*1 = {*0}
*2 = {*1} = *0
*3 = {*0,*2} = *1
*4 = {*1,*3} = {*1} = *0
*5 = {*2,*4} = {*0} = *1
*/

#include<cstdio>

long long n;
int main()
{
    scanf("%lld", &n);
    printf("%s", n%2==0?"CY":"SK");
}