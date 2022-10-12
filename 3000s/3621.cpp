#include<bits/stdc++.h>
using namespace std;

int ar[100001];

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        ar[t]++;
    }
    int s = 0;
    for(int i=0 ; i<=n ; i++) {
        if(ar[i] > d) {
            while(ar[i] > d) {
                s++;
                ar[i] -= (d-1);
            }
        }
    }
    printf("%d", s);
}