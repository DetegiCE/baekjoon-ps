#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MP(A,B) make_pair(A,B)

double p[4][2];
bool issame(int a, int b) {
    if(p[a][0] == p[b][0] && p[a][1] == p[b][1]) return true;
    return false;
}

void calc(int f, int d, int e) {
    cout << p[f][0] - p[d][0] + p[e][0] << ' ' << p[f][1] - p[d][1] + p[e][1] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed;
    cout.precision(3);
    
    while(cin >> p[0][0] >> p[0][1] >> p[1][0] >> p[1][1] >> p[2][0] >> p[2][1] >> p[3][0] >> p[3][1]) {
        if(issame(0, 2)) calc(3, 0, 1);
        else if(issame(0, 3)) calc(2, 0, 1);
        else if(issame(1, 2)) calc(3, 1, 0);
        else if(issame(1, 3)) calc(2, 1, 0);
    }
}
