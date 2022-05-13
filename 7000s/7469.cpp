#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int>::iterator iit;

int n, m, cnt;
int a[100001];
vector<int> tree[270000];

void mergeTree(int k) {
    int lef = k*2;
    int rig = k*2+1;
    iit lefit = tree[lef].begin();
    iit rigit = tree[rig].begin();
    while(lefit != tree[lef].end() && rigit != tree[rig].end()) {
        if(*lefit > *rigit) {
            tree[k].push_back(*rigit);
            rigit++;
        }
        else {
            tree[k].push_back(*lefit);
            lefit++;
        }
    }
    while(lefit != tree[lef].end()) {
        tree[k].push_back(*lefit);
        lefit++;
    }
    while(rigit != tree[rig].end()) {
        tree[k].push_back(*rigit);
        rigit++;
    }
}

int getQuery(int lef, int rig, int k) {
    lef = lef+cnt-1;
    rig = rig+cnt-1;
    int sum = 0;
    while(lef < rig) {
        if(lef%2==1) {
            sum += tree[lef].end()-upper_bound(tree[lef].begin(),tree[lef].end(),k);
            lef++;
        }
        if(rig%2==0) {
            sum += tree[rig].end()-upper_bound(tree[rig].begin(),tree[rig].end(),k);
            rig--;
        }
        lef/=2;
        rig/=2;
    }
    if(lef == rig) {
        sum += tree[lef].end()-upper_bound(tree[lef].begin(),tree[lef].end(),k);
    }
    return sum;
}

int main()
{
    scanf("%d %d",&n, &m);
    for(int i=0 ; i<n ; i++) {
        scanf("%d",&a[i]);
    }
    for(cnt=1 ; cnt<n ; cnt<<=1);
    for(int i=0 ; i<n ; i++) {
        tree[i+cnt].push_back(a[i]);
    }
    for(int i=cnt-1 ; i>=1 ; i--) {
        mergeTree(i);
    }
    for(int i=0 ; i<m ; i++) {
        int lef,rig,k;
        scanf("%d %d %d",&lef,&rig,&k);
        int left = -1000000001;
        int right = 1000000001;
        int mid;
        while(left <= right) {
            mid = (left + right) / 2;
            int tempans = getQuery(lef, rig, mid);
            if(tempans > k) left = mid + 1;
            else right = mid - 1;
        }
        if(right < -1000000001) puts("0");
        else printf("%d\n",right);
    }
}