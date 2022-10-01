#include<bits/stdc++.h>
using namespace std;

class Number {
public:
    int num;
    int pos;
    Number(int num, int pos): num(num), pos(pos) {}
    
    bool operator< (const Number &n) const {
        if(num == n.num) return pos < n.pos;
        else return num < n.num;
    }
};

int n;
vector<Number> v;

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        v.push_back(Number(t, i));
    }
    sort(v.begin(), v.end());
    
    vector<int> ans(n, 0);
    for(int i=0 ; i<n ; i++) {
        ans[v[i].pos] = i;
    }
    for(int i=0 ; i<n ; i++) {
        printf("%d ", ans[i]);
    }
}