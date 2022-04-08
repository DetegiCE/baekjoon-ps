#include <cstdio>
#include <deque>
#include <utility>
using namespace std;
#define mp(a, b) make_pair(a, b)

typedef pair<int, int> pii;

int n;
deque<pii> dq;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        dq.push_back(mp(t, i + 1));
    }
    while (!dq.empty()) {
        int num = dq.front().first;
        printf("%d ", dq.front().second);
        dq.pop_front();
        if (dq.empty()) break;
        if (num > 0) {
            for (int i = 0; i < num - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < (num * -1); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}