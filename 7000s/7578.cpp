#include<cstdio>
#include<vector>
using namespace std;

typedef long long int ll;

int n;
vector<int> a;
int pos[1000001];

// my seg tree
ll sum[1048576];
int start;

ll getSum(int left, int right) {
    ll thisSum = 0;
    while (left < right) {
        if (left & 1 == 1) thisSum += sum[left++];
        if (right & 1 == 0) thisSum += sum[right--];
        left >>= 1;
        right >>= 1;
    }
    if (left == right) thisSum += sum[left];
    return thisSum;
}

void updateSum(int pos) {
    while(pos > 1) {
        pos >>= 1;
        sum[pos] = sum[pos<<1] + sum[(pos<<1)+1];
    }
}

int main()
{
    int t;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &t);
        a.push_back(t);
    }
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &t);
        pos[t] = i;
    }
    for(start=1 ; start<n ; start<<=1);
    
    ll ans = 0;
    for(int i=0 ; i<n ; i++) {
        ans += getSum(start+pos[a[i]], start*2-1);
        sum[start+pos[a[i]]] = 1;
        updateSum(start+pos[a[i]]);
    }

    printf("%lld", ans);
}
