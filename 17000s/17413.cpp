#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> st;

int main() {
    char s[100001];
    scanf("%[^\n]s", s);
    int len = strlen(s);

    bool isopen = false;
    for (int i = 0; i < len; i++) {
        if (s[i] == '<') {
            isopen = true;
            while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }
            printf("<");
        } else if (s[i] == '>') {
            isopen = false;
            printf(">");
        } else if (s[i] == ' ') {
            if (isopen) {
                printf(" ");
            } else {
                while (!st.empty()) {
                    printf("%c", st.top());
                    st.pop();
                }
                printf(" ");
            }
        } else {
            if (isopen) {
                printf("%c", s[i]);
            } else {
                st.push(s[i]);
            }
        }
    }
    while (!st.empty()) {
        printf("%c", st.top());
        st.pop();
    }
}