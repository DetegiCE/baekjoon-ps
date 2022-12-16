#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

typedef struct player {
    ll ac_cnt;
    ll score;
    ll ac_time[11];
    ll wa_cnt[11];
    ll id;
} PLYR;

PLYR plyr_list[501];

bool compare(PLYR a, PLYR b) {
    if(a.ac_cnt == b.ac_cnt) {
        return a.score < b.score;
    }
    else return a.ac_cnt > b.ac_cnt;
}

void sol() {
    int M, N, P;
    cin >> M >> N >> P;
    for(int i=1 ; i<=P ; i++) {
        plyr_list[i].score = 0;
        plyr_list[i].ac_cnt = 0;
        plyr_list[i].id = i;
        for(int j=1 ; j<=M ; j++) {
            plyr_list[i].ac_time[j] = 0;
            plyr_list[i].wa_cnt[j] = 0;
        }
    }
    for(int i=0 ; i<N ; i++) {
        int p, t, j;
        char m;
        cin >> p >> m >> t >> j;
        if(j == 0) {
            if(plyr_list[p].ac_time[m-'A'+1] == 0) {
                plyr_list[p].wa_cnt[m-'A'+1]++;
            }
        }
        else {
            if(plyr_list[p].ac_time[m-'A'+1] == 0) {
                plyr_list[p].ac_time[m-'A'+1] = t;
                plyr_list[p].ac_cnt++;
            }
        }
    }
    for(int i=1 ; i<=P ; i++) {
        for(int j=1 ; j<=M ; j++) {
            if(plyr_list[i].ac_time[j] > 0)
                plyr_list[i].score += plyr_list[i].ac_time[j] + plyr_list[i].wa_cnt[j] * 20;
        }
    }
    sort(plyr_list+1, plyr_list+P+1, compare);
    for(int i=1 ; i<=P ; i++) {
        cout << plyr_list[i].id << ' ' << plyr_list[i].ac_cnt << ' ' << plyr_list[i].score << '\n';
    }
    cout << '\n';
}

int main()
{
    INP;
    
    int k;
    cin >> k;
    for(int i=1 ; i<=k ; i++) {
        cout << "Data Set " << i << ":\n";
        sol();
    }
}