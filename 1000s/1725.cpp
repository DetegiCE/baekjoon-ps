#include<cstdio>
#include<stack>
#include<utility>
using namespace std;

#define MAX(A,B) (A>B?A:B)

stack<int> st;
int mx, blim;
int hist[100001];

int main()
{
    int n, t;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &hist[i]);
        while(!st.empty() && hist[st.top()] > hist[i]) {
            int curlim = 0;
            blim = st.top(); st.pop();
            if(st.empty()) {
                curlim = i;
            } 
            else {
                curlim = i - st.top() - 1;
            }
            mx = MAX(mx, hist[blim] * curlim);
        }
        st.push(i);
    }
    while(!st.empty() && hist[st.top()] > hist[n]) {
        int curlim = 0;
        blim = st.top(); st.pop();
        if(st.empty()) {
            curlim = n;
        } 
        else {
            curlim = n - st.top() - 1;
        }
        mx = MAX(mx, hist[blim] * curlim);
    }
    printf("%d", mx);
}
