#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char s[101];
    scanf("%d", &n);
    scanf(" %s", s);
    for(int i=0 ; i<n ; i++) {
        if(s[i] == '?') {
            if(s[n-i-1] == '?') {
                printf("a");
            }
            else {
                printf("%c", s[n-i-1]);
            }
        }
        else {
            printf("%c", s[i]);
        }
    }
    
}