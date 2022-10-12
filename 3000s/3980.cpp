#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v[12];
bool used[12];
int mx;

void f(int num, int tot) {
    if(num == 11) {
        mx = max(mx, tot);
        return;
    }
    for(int i=0 ; i<v[num].size() ; i++) {
        int posi = v[num][i].first;
        int scor = v[num][i].second;
        if(!used[posi]) {
            used[posi] = true;
            f(num+1, tot+scor);
            used[posi] = false;
        }
    }
}

void sol() {
    mx = 0;
    for(int i=0 ; i<11 ; i++) {
        v[i].clear();
        used[i] = false;
        for(int j=0 ; j<11 ; j++) {
            int t;
            scanf("%d", &t);
            if(t > 0) {
                v[i].push_back(make_pair(j, t));
            }
        }
    }
    f(0, 0);
    printf("%d\n", mx);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        sol();
    }
}