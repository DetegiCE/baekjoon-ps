#include <bits/stdc++.h>
using namespace std;

int ss[1000001];
// 0: dont' know, 1: ss, 2: visited, 3: non ss

bool sieve[1000001];
vector<int> prime;

void makeprime(int v) {
    sieve[0] = sieve[1] = true;
    for (int i = 3; i <= v; i += 2) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (int j = i * 3; j <= v; j += i * 2) {
                sieve[j] = true;
            }
        }
    }
}

void f(int n) {
    if (n == 1) return;
    if (ss[n] > 0) return;
    int s = 0;
    int m = n;
    while (m > 0) {
        s += (m % 10) * (m % 10);
        m /= 10;
    }
    ss[n] = 2;
    f(s);
    if (ss[s] == 1) {
        ss[n] = 1;
        return;
    }
    if (ss[s] == 2 || ss[s] == 3) {
        ss[n] = 3;
        return;
    }
}

int main() {
    makeprime(1000000);

    int n;
    scanf("%d", &n);
    ss[1] = 1;
    ss[2] = ss[3] = ss[4] = ss[5] = ss[6] = 3;
    for (int i = 7; i <= n; i += 2) {
        if (ss[i] == 0) f(i);
        if (ss[i] == 1 && !sieve[i]) printf("%d\n", i);
    }
}