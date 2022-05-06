#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int n;
vector<int> trees;
vector<int> diff;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end(), greater<int>() );
    for(int i=0 ; i<n-1 ; i++) {
        diff.push_back(trees[i]-trees[i+1]);
    }
    int g = gcd(diff[0], diff[1]);
    for(int i=2 ; i<n-1 ; i++) {
        g = gcd(g, diff[i]);
    }
    printf("%d", (trees[0]-trees[n-1])/g+1-n);
}