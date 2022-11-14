#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)

typedef struct stu {
    int num;
    int votes;
    int date;
} STU;

vector<STU> v;

int main()
{
    int n, q, a;
    cin >> n >> q;
    for(int i=0 ; i<q ; i++) {
        cin >> a;
        bool flg = false;
        for(int j=0 ; j<v.size() ; j++) {
            if(v[j].num == a) {
                v[j].votes++;
                flg = true;
                break;
            }
        }
        if(flg) {
            continue;
        }
        else {
            if(v.size() == n) {
                int minvotes = 99999;
                for(int j=0 ; j<n ; j++) {
                    minvotes = min(minvotes, v[j].votes);
                }
                int mindates = 99999;
                for(int j=0 ; j<n ; j++) {
                    if(v[j].votes == minvotes)
                        mindates = min(mindates, v[j].date);
                }
                for(int j=0 ; j<n ; j++) {
                    if(v[j].votes == minvotes && v[j].date == mindates) {
                        v[j].num = a;
                        v[j].votes = 1;
                        v[j].date = i;
                        break;
                    }
                }
            }
            else {
                STU newstu = {a, 1, i};
                v.push_back(newstu);
            }
        }
    }
    vector<int> vt;
    for(auto k: v) {
        vt.push_back(k.num);
    }
    sort(vt.begin(), vt.end());
    for(auto k: vt) {
        cout << k << ' ';
    }
}