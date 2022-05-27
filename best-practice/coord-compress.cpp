#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int arr[10000];
vector<int> tmp;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &arr[i]);
        tmp.push_back(arr[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i=0 ; i<n ; i++) {
        int idx = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
        printf("%d ", idx);
    }
}