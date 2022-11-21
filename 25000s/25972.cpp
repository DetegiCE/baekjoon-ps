#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 987654321
#define PB(A) push_back(A)
#define MP(A,B) make_pair(A,B)
typedef long long ll;
typedef pair<int,int> pii;

int n, cnt = 0, cpos = 0;
vector<pii> v;

int main()
{
    INP;
    
    cin >> n;
    
    for(int i=0 ; i<n ; i++) {
        int a, l;
        cin >> a >> l;
        v.PB(MP(a,l));
    }
    sort(v.begin(), v.end());
    for(int i=0 ; i<n ; i++) {
        if(v[i].first > cpos) {
            cnt++;
        }
        cpos = v[i].first + v[i].second;
    }
    
    cout << cnt;
}