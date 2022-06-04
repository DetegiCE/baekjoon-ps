#include<iostream>
using namespace std;

int main()
{
    int t;
    while(cin >> t) {
        if(t == 1) {
            cout << '1' << '\n';
            continue;
        }
        int a = 1, cnt = 2;
        while((a*10+1)%t > 0) {
            cnt++;
            a = (a*10+1)%t;
        } 
        cout << cnt << '\n';
    }
}