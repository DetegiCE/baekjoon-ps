#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <vector>
using namespace std;

struct ice {
    vector<int> vi;
    deque<int> dq;
};

map<int, ice> mp;
bool rev;

int main() {
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        mp[-t].vi.push_back(i);
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort(it->second.vi.begin(), it->second.vi.end());
        for (int i = 0; i < it->second.vi.size(); i++) {
            it->second.dq.push_back(it->second.vi[i]);
        }
        while (!(it->second.dq.empty())) {
            if (rev) {
                printf("%d\n", it->second.dq.back());
                it->second.dq.pop_back();
            } else {
                printf("%d\n", it->second.dq.front());
                it->second.dq.pop_front();
            }
            cnt++;
            if (cnt == m) return 0;
            if (it->first % 7 == 0) rev = !rev;
        }
    }
    return 0;
}