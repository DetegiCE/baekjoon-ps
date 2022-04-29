#include<iostream>
#include<deque>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator < (const Query &x) const {
        if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

int n, k, m;
int v[101000];
int ans[101000];
vector<Query> query;
deque<int> dq[101000];
int curmax;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    sqrtN = sqrt(n);
    for(int i=1 ; i<=n ; i++) {
        cin >> v[i];
    }
    cin >> m;
    for(int i=0 ; i<m ; i++) {
        int s, e;
        cin >> s >> e;
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for(int i=s ; i<=e ; i++) {
        dq[v[i]].push_back(i);
    }

    for(int i=1 ; i<m ; i++) {

    }
}