#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }
    
    int cnt = 0;
    do {
        cnt++;
        if(cnt == 2) {
            for(int i: v) {
                printf("%d ", i);
            }
            break;
        }
    } while(prev_permutation(v.begin(), v.end()));
    if(cnt == 1) puts("-1");
}