#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> pii;

typedef struct classroom {
    int etime;
    int no;
} CLSRM;

struct compare {
    bool operator()(const CLSRM& c1, const CLSRM& c2) {
        return c1.etime > c2.etime;
    }
};

int n;
vector<pii> clses;
priority_queue<CLSRM, vector<CLSRM>, compare> pq;

int tot;
priority_queue<int, vector<int>, greater<int> > unoccup;

int main() 
{
    INP;
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        clses.push_back(make_pair(a, b));
    }
    sort(clses.begin(), clses.end());
    
    for(int i=0 ; i<n ; i++) {
        while(!pq.empty()) {
            if(pq.top().etime <= clses[i].first) {
                unoccup.push(pq.top().no);
                pq.pop();
            }
            else break;
        }
        if(unoccup.empty()) {
            tot++;
            pq.push({clses[i].second, tot});
        }
        else {
            pq.push({clses[i].second, unoccup.top()});
            unoccup.pop();
        }
    }
    cout << tot;
}