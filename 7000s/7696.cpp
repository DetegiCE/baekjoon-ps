#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int cnt = 0, cur = 0;
    while(cnt <= 1000000) {
        int dig[10] = {0,0,0,0,0,0,0,0,0,0};
        cur++;
        int dur = cur;
        bool unv = false;
        while(dur > 0) {
            dig[dur % 10] ++;
            if(dig[dur%10] > 1) {
                unv = true;
                break;
            }
            dur /= 10;
        }
        if(unv) continue;
        a.push_back(cur);
        cnt++;
    }
    while(1) {
        int b;
        scanf("%d", &b);
        if(b == 0) {
            break;
        }
        printf("%d\n", a[b-1]);
    }
}