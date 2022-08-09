#include<cstdio>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

#define MP(A,B) make_pair(A,B)

typedef long long ll;
typedef pair<int,int> pii;

ll n, cnt, tcnt;
char stt[2000001];
int pairnum[2000001];
stack<int> st;
vector<pii> pars[1000001];

int lev = 0;
int mxlev;

int main()
{
    scanf("%lld", &n);
    scanf("%s", stt);
    for(int i=0 ; i<n ; i++) {
        pairnum[i] = -1;
        if(stt[i] == '(') {
            st.push(i);
        }
        else {
            if(st.empty()) tcnt = 0;
            else {
                pairnum[st.top()] = i;
                pairnum[i] = st.top();
                st.pop();
            }
        }
    }
    for(int i=0 ; i<n ; i++) {
        if(pairnum[i] == -1) continue;

        if(pairnum[i] > i) {
            lev++;
            if(lev>mxlev) mxlev = lev;
            pars[lev].push_back(MP(i, pairnum[i]));
        }
        else {
            lev--;
        }
    }

    for(int i=1 ; i<=mxlev ; i++) {
        tcnt = 1;
        cnt++;
        for(int j=1 ; j<pars[i].size() ; j++) {
            if(pars[i][j-1].second + 1 == pars[i][j].first) {
                tcnt++;
            }
            else tcnt = 1;
            cnt += tcnt;
        }
    }
    printf("%lld", cnt);
}