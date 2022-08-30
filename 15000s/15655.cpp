#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for(int i=0 ; i<m ; i++) b.push_back(0);
    for(int i=0 ; i<n-m ; i++) b.push_back(1);
    
    do {
        for(int i=0 ; i<n ; i++) {
            if(b[i] == 0) {
                printf("%d ", a[i]);
            }
        }
        puts("");
    } while(next_permutation(b.begin(), b.end()));
}