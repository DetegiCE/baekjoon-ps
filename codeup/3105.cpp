#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int a[50002];
vector<int> v[50002];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    for(int i=1 ; i<=50000 ; i++) {
        if(a[i] >= 1) {
            v[a[i]].push_back(i);
        }
    }
    for(int i=50000 ; i>=1 ; i--) {
        if(v[i].size() > 0) {
            sort(v[i].begin(), v[i].end(), greater<int>());
        }
        for(int j=0 ; j<v[i].size() ; j++) {
            for(int k=0 ; k<i ; k++) printf("%d ", v[i][j]);
        }
    }
}