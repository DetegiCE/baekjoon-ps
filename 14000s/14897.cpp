#pragma GCC optimize("O3")
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator < (const Query &x) const {
        if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
vector<int> tmp;
int cnt[1000005];
int ans[1000005];
int res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n;
    sqrtN = sqrt(n);
    v.resize(n+1);
    for(int i=1 ; i<=n ; i++) {
        cin >> v[i];
        tmp.push_back(v[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i=1 ; i<=n ; i++) {
        v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
    }

    cin >> q;
    for(int i=0 ; i<q ; i++) {
        int s, e;
        cin >> s >> e;
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s ; i<=e ; i++) {
        cnt[v[i]]++;
        if(cnt[v[i]] == 1) {
            res++;
        }
    }
    ans[query[0].idx] = res;

    for(int i=1 ; i<q ; i++) {
        while(s < query[i].s) {
            cnt[v[s]]--;
            if(cnt[v[s]] == 0) res--;
            s++;
        }
        while(s > query[i].s) {
            s--;
            cnt[v[s]]++;
            if(cnt[v[s]] == 1) res++;
        }
        while(e < query[i].e) {
            e++;
            cnt[v[e]]++;
            if(cnt[v[e]] == 1) res++;
        }
        while(e > query[i].e) {
            cnt[v[e]]--;
            if(cnt[v[e]] == 0) res--;
            e--;
        }
        ans[query[i].idx] = res;
    }
    for(int i=0 ; i<q ; i++) {
        cout << ans[i] << '\n';
    }
}