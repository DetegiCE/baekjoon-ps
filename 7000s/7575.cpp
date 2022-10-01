#include<bits/stdc++.h>
using namespace std;

int n, k;
int m[101];
vector<int> v[101];
vector<int> code;

vector<int> generatePi(int num) {

}

bool kmp(int num) {
    vector<int> pi = generatePi(num);
    
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &m[i]);
        for(int j=0 ; j<m[i] ; j++) {
            int t;
            scanf("%d", &t);
            v[i].push_back(t);
        }
    }

    for(int i=0 ; i<m[0]-k+1 ; i++) {
        code.clear();
        for(int j=0 ; j<k ; j++) {
            code.push_back(v[0][i+j]);
        }
        vector<bool> hasvirus(n, false);
        for(int j=1 ; j<n ; j++) {
            hasvirus[j] = kmp(j);
        }

    }
}