#include<bits/stdc++.h>
using namespace std;
#define INP ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;

int main()
{
    INP;
    
    string a;
    cin >> a;
    
    int alen = a.length();
    for(int i=0 ; i<alen ; i++) {
        if(a[i] == 'p') {
            if(i != alen-1 && a[i+1] == 'i') {
                i++;
                continue;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        else if(a[i] == 'k') {
            if(i != alen-1 && a[i+1] == 'a') {
                i++;
                continue;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        else if(a[i] == 'c') {
            if(i <= alen-2 && a[i+1] == 'h' && a[i+2] == 'u') {
                i+=2;
                continue;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
