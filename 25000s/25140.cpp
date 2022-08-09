#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define C1(A) (A / 100000000)
#define C2(A) (A / 10000000 % 10)
#define C3(A) (A / 1000000 % 10)
#define C4(A) (A / 100000 % 10)
#define C5(A) (A / 10000 % 10)
#define C6(A) (A / 1000 % 10)
#define C7(A) (A / 100 % 10)
#define C8(A) (A / 10 % 10)
#define C9(A) (A % 10)

#define MP(A, B) make_pair(A, B)

typedef pair<int, vector<int> > piv;

queue<piv> q;
set<int> vis;

int gettopnum(int val) {
    if (!C4(val)) return C1(val);
    if (!C5(val)) return C2(val);
    if (!C6(val)) return C3(val);
    if (!C7(val)) return C4(val);
    if (!C8(val)) return C5(val);
    if (!C9(val)) return C6(val);
    return -1;
}

int gettopval(int val) {
    if (!C4(val)) return val - C1(val) * 1e8 + C1(val) * 1e5;
    if (!C5(val)) return val - C2(val) * 1e7 + C2(val) * 1e4;
    if (!C6(val)) return val - C3(val) * 1e6 + C3(val) * 1e3;
    if (!C7(val)) return val - C4(val) * 1e5 + C4(val) * 100;
    if (!C8(val)) return val - C5(val) * 1e4 + C5(val) * 10;
    if (!C9(val)) return val - C6(val) * 1e3 + C6(val);
}

int getbotnum(int val) {
    if (!C1(val)) return C4(val);
    if (!C2(val)) return C5(val);
    if (!C3(val)) return C6(val);
    if (!C4(val)) return C7(val);
    if (!C5(val)) return C8(val);
    if (!C6(val)) return C9(val);
    return -1;
}

int getbotval(int val) {
    if (!C1(val)) return val - C4(val) * 1e5 + C4(val) * 1e8;
    if (!C2(val)) return val - C5(val) * 1e4 + C5(val) * 1e7;
    if (!C3(val)) return val - C6(val) * 1e3 + C6(val) * 1e6;
    if (!C4(val)) return val - C7(val) * 100 + C7(val) * 1e5;
    if (!C5(val)) return val - C8(val) * 10 + C8(val) * 1e4;
    if (!C6(val)) return val - C9(val) + C9(val) * 1e3;
}

int getlefnum(int val) {
    if (!C2(val)) return C1(val);
    if (!C3(val)) return C2(val);
    if (!C5(val)) return C4(val);
    if (!C6(val)) return C5(val);
    if (!C8(val)) return C7(val);
    if (!C9(val)) return C8(val);
    return -1;
}

int getlefval(int val) {
    if (!C2(val)) return val - C1(val) * 1e8 + C1(val) * 1e7;
    if (!C3(val)) return val - C2(val) * 1e7 + C2(val) * 1e6;
    if (!C5(val)) return val - C4(val) * 1e5 + C4(val) * 1e5;
    if (!C6(val)) return val - C5(val) * 1e4 + C5(val) * 1e3;
    if (!C8(val)) return val - C7(val) * 100 + C7(val) * 10;
    if (!C9(val)) return val - C8(val) * 10 + C8(val);
}

int getrignum(int val) {
    if (!C1(val)) return C2(val);
    if (!C2(val)) return C3(val);
    if (!C4(val)) return C5(val);
    if (!C5(val)) return C6(val);
    if (!C7(val)) return C8(val);
    if (!C8(val)) return C9(val);
    return -1;
}

int getrigval(int val) {
    if (!C1(val)) return val - C2(val) * 1e7 + C2(val) * 1e8;
    if (!C2(val)) return val - C3(val) * 1e6 + C3(val) * 1e7;
    if (!C4(val)) return val - C5(val) * 1e4 + C5(val) * 1e5;
    if (!C5(val)) return val - C6(val) * 1e3 + C6(val) * 1e4;
    if (!C7(val)) return val - C8(val) * 10 + C8(val) * 100;
    if (!C8(val)) return val - C9(val) + C9(val) * 10;
}

int main() {
    char a[9];
    scanf("%c %c %c", &a[0], &a[1], &a[2]);
    scanf(" %c %c %c", &a[3], &a[4], &a[5]);
    scanf(" %c %c %c", &a[6], &a[7], &a[8]);
    int num = 0;
    for (int i = 0; i < 9; i++) {
        num *= 10;
        num += a[i] == 'X' ? 0 : a[i] - '0';
    }

    vector<int> v;
    vis.insert(num);
    q.push(MP(num, v));
    while (!q.empty()) {
        piv qf = q.front();
        q.pop();
        printf("%d - ", qf.first);
        printf("%d\n", (int)qf.second.size());
        for (int i = 0; i < qf.second.size(); i++) {
            printf("%d ", qf.second[i]);
        }
        puts("");
        if (qf.first == 123456780) {
            printf("%d\n", (int)qf.second.size());
            for (int i = 0; i < qf.second.size(); i++) {
                printf("%d ", qf.second[i]);
            }
            break;
        }

        int topnum = gettopnum(qf.first);
        if (topnum != -1) {
            int topval = gettopval(qf.first);
            if (vis.find(topval) == vis.end()) {
                vector<int> vt(qf.second);
                vt.push_back(topnum);
                q.push(MP(topval, vt));
                vis.insert(topval);
            }
        }

        int botnum = getbotnum(qf.first);
        if (botnum != -1) {
            int botval = getbotval(qf.first);
            if (vis.find(botval) == vis.end()) {
                vector<int> vt(qf.second);
                vt.push_back(botnum);
                q.push(MP(botval, vt));
                vis.insert(botval);
            }
        }

        int lefnum = getlefnum(qf.first);
        if (lefnum != -1) {
            int lefval = getlefval(qf.first);
            if (vis.find(lefval) == vis.end()) {
                vector<int> vt(qf.second);
                vt.push_back(lefnum);
                q.push(MP(lefval, vt));
                vis.insert(lefval);
            }
        }

        int rignum = getrignum(qf.first);
        if (rignum != -1) {
            int rigval = getrigval(qf.first);
            if (vis.find(rigval) == vis.end()) {
                vector<int> vt(qf.second);
                vt.push_back(rignum);
                q.push(MP(rigval, vt));
                vis.insert(rigval);
            }
        }
    }
}