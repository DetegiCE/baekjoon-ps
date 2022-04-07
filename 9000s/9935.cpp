#include <iostream>
#include <stack>
#include <string>
using namespace std;

string a, b;
int bcur;
stack<char> ans;
stack<char> temp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a;
    cin >> b;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[b.length() - 1]) {
            if (ans.size() + 1 < b.length()) {
                ans.push(a[i]);
                continue;
            }
            int flag = 0;
            for (int j = b.length() - 2; j >= 0; j--) {
                if (ans.top() == b[j]) {
                    temp.push(ans.top());
                    ans.pop();
                } else {
                    flag = 1;
                    while (!temp.empty()) {
                        ans.push(temp.top());
                        temp.pop();
                    }
                    ans.push(a[i]);
                    break;
                }
            }
            if (flag == 0) {
                while (!temp.empty()) temp.pop();
            }
        } else {
            ans.push(a[i]);
        }
    }
    while (!temp.empty()) temp.pop();
    while (!ans.empty()) {
        temp.push(ans.top());
        ans.pop();
    }

    if (temp.size() == 0) {
        cout << "FRULA";
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
}
