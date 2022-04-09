#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;

int k, n;
priority_queue<ll, vector<ll>, greater<ll> > pq;
vector<ll> v;

int main() {
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        ll t;
        scanf("%lld", &t);
        v.push_back(t);
        pq.push(t);
    }
    for (int i = 0; i < n; i++) {
        ll head = pq.top();
        if (i == n - 1) {
            printf("%lld", head);
            break;
        }
        for (int j = 0; j < k; j++) {
            ll val = head * v[j];
            pq.push(val);
            if (head % v[j] == 0) break;
        }
        pq.pop();
    }
}