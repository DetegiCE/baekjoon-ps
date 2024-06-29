#include<bits/stdc++.h>
using namespace std;

typedef struct person {
    string name;
    int pos;
} PERSON;

PERSON p[1001];

int main()
{
    int n, tc = 0;
    cin >> n;
    while(n != 0) {
        tc++;
        for(int i=0 ; i<n ; i++) {
            cin >> p[i].name;
            p[i].pos = i;
        }
        for(int i=1 ; i<n ; i++) {
            PERSON cur = p[i];
            int j = i;
            while(j > 0 && p[j-1].name > cur.name) {
                p[j] = p[j-1];
                j--;
            }
            p[j] = cur;
        }

        int s = p[0].pos;
        for(int i=1 ; i<n ; i++) {
            s += abs(p[i].pos - i);
        }
        cout << "Site " << tc << ": " << s << '\n';
        cin >> n;
    }
}