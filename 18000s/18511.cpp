#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

int n, k;
vector<int> v;
int mx;

void f(int sum) {
    if(sum > n) return;
    mx = max(mx, sum);
    f(sum*10+v[0]);
    if(k>1) f(sum*10+v[1]);
    if(k>2) f(sum*10+v[2]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=0 ; i<k ; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    f(0);
    cout << mx;
}