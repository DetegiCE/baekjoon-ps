#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator < (const Query &x) const {
        if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

int n, q;
int v[101000];
vector<Query> query;
int ans[101000];
int curmax;
int cnt[101000]; // cnt[i] = i 값이 몇개 있는지
int table[101000]; // table[i] = i개인 수가 몇개 있는지

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    sqrtN = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int sqrtN = sqrt(n);

    cin >> q;
    for(int i=0 ; i<q ; i++) {
        int s, e;
        cin >> s >> e;
        Query myQuery = {i, s, e};
        query.push_back(myQuery);
    }

    sort(query.begin(), query.end());
    int s = 0, e = 0;
    for(int i=0 ; i<q ; i++) {
        while(s < query[i].s) {
            table[cnt[v[s]]]--;
            if(cnt[v[s]] == curmax && table[cnt[v[s]]] == 0) {
                curmax--;
            }
            cnt[v[s]]--;
            table[cnt[v[s]]]++;
            s++;
        }
        while(s > query[i].s) {
            s--;
            if(cnt[v[s]] != 0) table[cnt[v[s]]]--;
            cnt[v[s]]++;
            table[cnt[v[s]]]++;
            curmax = MAX(curmax, cnt[v[s]]);
        }
        while(e < query[i].e) {
            e++;
            if(cnt[v[e]] != 0) table[cnt[v[e]]]--;
            cnt[v[e]]++;
            table[cnt[v[e]]]++;
            curmax = MAX(curmax, cnt[v[e]]);
        }
        while(e > query[i].e) {
            table[cnt[v[e]]]--;
            if(cnt[v[e]] == curmax && table[cnt[v[e]]] == 0) {
                curmax--;
            }
            cnt[v[e]]--;
            table[cnt[v[e]]]++;
            e--;
        }
        ans[query[i].idx] = curmax;

        // cout << query[i].s << ' ' << query[i].e << '\n';
        // for(int j=0 ; j<=5 ; j++) cout << cnt[j] << ' ';
        // cout << '\n';
        // for(int j=0 ; j<=5 ; j++) cout << table[j] << ' ';
        // cout << '\n';
    }
    for(int i=0 ; i<q ; i++) {
        cout << ans[i] << '\n';
    }
}