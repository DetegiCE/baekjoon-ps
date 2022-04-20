#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k;
vector<string> v;
vector<int> vi;

bool comp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    } else
        return a.length() > b.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        v.push_back(t);
    }
    cin >> k;
    sort(v.begin(), v.end(), comp);
    for (auto &i : v) {
        vi.push_back(i.length());
    }
    for (int i = 0; i < k; i++) {
    }
}