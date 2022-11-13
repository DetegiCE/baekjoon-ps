#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0); cin.tie(0)
#define PB(A) push_back(A)

int main()
{
    INP;
    
    string s;
    cin >> s;
    int arr[1003];
    int sum[1003];
    int slen = s.length();
    for(int i=0 ; i<slen ; i++) {
        arr[i+1] = (s[i] - '0');
    }
    sum[0] = 0;
    for(int i=1 ; i<=slen ; i++) {
        sum[i] = sum[i-1] + arr[i];   
    }
    for(int i=slen/2 ; i>=1 ; i--) {
        for(int j=1 ; j<=slen-i*2+1 ; j++) {
            int left = sum[j+i-1] - sum[j-1];
            int right = sum[j+i*2-1] - sum[j+i-1];
            if(left == right) {
                cout << i*2;
                return 0;
            }
        }
    }
}