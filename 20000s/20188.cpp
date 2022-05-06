#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;

vector<ll> tree[300003];
ll child[300003];
ll n;
ll sum;

ll getchild(int idx, int par) {
    ll sz = tree[idx].size();
    child[idx] = 1;
    for(int i=0 ; i<sz ; i++) {
        if(tree[idx][i] == par) continue;
        child[idx] += getchild(tree[idx][i], idx);
    }
    return child[idx];
}

int main()
{
    scanf("%lld", &n);
    for(int i=0 ; i<n-1 ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    child[1] = getchild(1, 0);
    for(int i=2 ; i<=n ; i++) {
        sum += (n-child[i])*(n-child[i]-1)/2;
    }
    printf("%lld", (n-1)*n*(n-1)/2 - sum);
}