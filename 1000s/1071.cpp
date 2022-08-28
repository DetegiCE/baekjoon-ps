#include<bits/stdc++.h>
using namespace std;

int num[1001];
int n, numcnt;
vector<int> v;

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        num[t]++;
        if(num[t] == 1) {
            numcnt++;
            v.push_back(t);
        }
    }
    sort(v.begin(), v.end());
    // printf("vsz %d\n",v.size());

    int bef = -1;
    for(int i=0 ; i<n ; i++) {
        if(numcnt == 1){
            int a = 0;
            for(int j=0 ; j<v.size() ; j++) {
                if(num[v[j]] != 0) {
                    a = v[j];
                    break;
                }
            }
            for(int j=0 ; j<num[a] ; j++) {
                printf("%d ", a);
            }
            numcnt--;
            return 0;
        }
        else if(numcnt == 2) {
            int a = -1, b = -1;
            for(int j=0 ; j<v.size() ; j++) {
                if(num[v[j]] != 0) {
                    if(a == -1) {
                        a = v[j];
                    }
                    else {
                        b = v[j];
                        break;
                    }
                }
            }
            if(bef!=-1 && bef+1==a && a+1!=b) {
                printf("%d ", b);
                for(int j=0 ; j<num[a] ; j++) printf("%d ", a);
                for(int j=0 ; j<num[b]-1 ; j++) printf("%d ", b);
            }
            else if(a + 1 == b) {
                for(int j=0 ; j<num[b] ; j++) printf("%d ", b);
                for(int j=0 ; j<num[a] ; j++) printf("%d ", a);
            }
            else {
                for(int j=0 ; j<num[a] ; j++) printf("%d ", a);
                for(int j=0 ; j<num[b] ; j++) printf("%d ", b);
            }
            numcnt -= 2;
            return 0;
        }
        else {
            if(bef == -1) {
                printf("%d ", v[0]);
                bef = v[0];
                num[v[0]] --;
                if(num[v[0]] == 0) numcnt--;
            }
            else {
                for(int j=0 ; j<v.size() ; j++) {
                    if((bef + 1 != v[j]) && num[v[j]]) {
                        printf("%d ", v[j]);
                        bef = v[j];
                        num[v[j]] --;
                        if(num[v[j]] == 0) numcnt--;
                        break;
                    }
                }
            }
        }
    }
}