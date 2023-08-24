#include<stdio.h>
#include<string.h>

int main()
{
    int n, m, cnt = 0;
    char a[53][53];
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf(" %s", a[i]);
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=1 ; j<m ; j++) {
            if(a[i][j-1] != a[i][j]) cnt++;
        }
    }
    for(int i=0 ; i<n-1 ; i++) {
        if(i % 2 == 0) {
            for(int j=1 ; j<m ; j++) {
                if(a[i][j] != a[i+1][j-1]) cnt++;
            }
        }
        else {
            for(int j=0 ; j<m ; j++) {
                if(a[i][j] != a[i+1][j]) cnt++;
            }
        }
    }
    for(int i=0 ; i<n-1 ; i++) {
        if(i % 2 == 0) {
            for(int j=0 ; j<m ; j++) {
                if(a[i][j] != a[i+1][j]) cnt++;
            }
        }
        else {
            for(int j=0 ; j<m-1 ; j++) {
                if(a[i][j] != a[i+1][j+1]) cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
