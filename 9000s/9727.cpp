#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool chk(const vector<int>& a) {
    set<int> s(a.begin(), a.end());
    for (int i = 1; i <= 6; ++i)
        if (s.find(i) == s.end()) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case#" << tc << ": ";
        vector<vector<int>> a(6, vector<int>(6));
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                cin >> a[i][j];

        bool f = true;

        for (int i = 0; i < 6; ++i) {
            if (!chk(a[i])) f = false;

            vector<int> col;
            for (int j = 0; j < 6; ++j)
                col.push_back(a[j][i]);
            if (!chk(col)) f = false;
        }

        vector<int> diag1;
        for (int i = 0; i < 6; ++i)
            diag1.push_back(a[i][i]);
        if (!chk(diag1)) f = false;

        vector<int> diag2;
        for (int i = 0; i < 6; ++i)
            diag2.push_back(a[i][5 - i]);
        if (!chk(diag2)) f = false;

        for (int i = 0; i < 6; i += 2) {
            vector<int> block1 = {a[i][0], a[i][1], a[i][2], a[i+1][0], a[i+1][1], a[i+1][2]};
            vector<int> block2 = {a[i][3], a[i][4], a[i][5], a[i+1][3], a[i+1][4], a[i+1][5]};
            if (!chk(block1)) f = false;
            if (!chk(block2)) f = false;
        }

        cout << (f ? 1 : 0) << '\n';
    }

    return 0;
}
