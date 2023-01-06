#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int n, m;
vector<pii> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0 ; i<m ; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(MP(x,y));
    }
    for(int i=0 ; i<(1<<n) ; i++) {
        int flg = 0;
        for(int j=0 ; j<m ; j++) {
            bool one, two;
            if(v[j].first > 0) one = (((1<<(v[j].first-1))&i)!=0);
            else one = !(((1<<((-v[j].first)-1))&i)!=0);
            if(v[j].second > 0) two = (((1<<(v[j].second-1))&i)!=0);
            else two = !(((1<<((-v[j].second)-1))&i)!=0);
            if(!one && !two) {
                flg = 1;
                break;
            }
        }
        if(flg == 0) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
