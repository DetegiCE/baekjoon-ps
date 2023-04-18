#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using plc = pair<ll, char>;

int n;
vector<string> v;
vector<int> m;
ll va[10], sm;
bool isfirst[10];
vector<plc> vp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin.ignore();
        string s;
        cin >> s;
        isfirst[s[0]-65] = true;
        reverse(s.begin(), s.end());
        
        ll g = 1;
        for(char j: s) {
            va[j-65] += g;
            g *= 10;
        }
    }
    for(int i=0 ; i<10 ; i++) {
        vp.push_back(plc(va[i], i+65));
    }
    
    sort(vp.begin(), vp.end());
    if(isfirst[vp[0].second-65]) {
        for(int i=1 ; i<=9 ; i++) {
            if(!isfirst[vp[i].second-65]) {
                swap(vp[0], vp[i]);
                break;
            }
        }   
    }
    
    sort(vp.begin()+1, vp.end());
    
    for(int i=0 ; i<=9 ; i++) {
        sm += vp[i].first * i;
    }
    
    cout << sm;
}
