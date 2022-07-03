#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct words {
    string s;
    int power;

    words(string s, int power):
    s(s), power(power) {};
};

bool compare(words a, words b) {
    if(a.power == b.power) return a.s < b.s;
    else return a.power > b.power;
}

void sol() {
    int n;
    cin >> n;
    vector<words> v;
    for(int i=0 ; i<n ; i++) {
        string s;
        cin >> s;
        int sz = s.size();
        int pw = 0;
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            pw++;
        }
        for(int j=1 ; j<sz ; j++) {
            if((s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') && (s[j-1] != 'a' && s[j-1] != 'e' && s[j-1] != 'i' && s[j-1] != 'o' && s[j-1] != 'u')) {
                pw++;
            }
        }
        v.push_back(words(s, pw));
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0 ; i<n ; i++) {
        cout << v[i].s << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}