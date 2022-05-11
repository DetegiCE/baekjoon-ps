#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100001], b[100001];
int idx[100001], s[100001];

vector<int> lis;

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) scanf("%d", &a[i]);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &b[i]);
        idx[b[i]] = i;
    }
    for(int i=0 ; i<n ; i++) {
        s[i] = idx[a[i]];
    }
    lis.push_back(s[0]);
    for(int i=1 ; i<n ; i++) {
        vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), s[i]);
        if(it == lis.end()) lis.push_back(s[i]);
        else *it = s[i];
    }
    printf("%d", lis.size());
}