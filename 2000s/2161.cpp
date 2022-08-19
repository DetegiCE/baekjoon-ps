#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
        if (q.empty()) break;
        q.push(q.front());
        q.pop();
    }
}