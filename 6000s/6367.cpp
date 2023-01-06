#include<bits/stdc++.h>
using namespace std;
#define SQ(A) (A)*(A)

typedef tuple<int,int,int> t3i;
vector<t3i> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0 ; i<16 ; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        v.push_back(make_tuple(r, g, b));
    }
    while(true) {
        int r, g, b;
        cin >> r >> g >> b;
        if(r == -1) break;
        
        int dist = 9999999;
        t3i nr;
        for(int i=0 ; i<16 ; i++) {
            int rd = SQ(r-get<0>(v[i]));
            int gd = SQ(g-get<1>(v[i]));
            int bd = SQ(b-get<2>(v[i]));
            if(dist > rd + gd + bd) {
                dist = rd + gd + bd;
                nr = v[i];
            }
        }
        cout << "(" << r << ',' << g << ',' << b << ") maps to (";
        cout << (get<0>(nr)) << ',' << (get<1>(nr)) << ',' << (get<2>(nr)) << ")\n";
    }
}
