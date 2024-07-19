#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y, m, d, n;
    scanf("%d-%d-%d", &y, &m, &d);
    scanf("%d", &n);
    
    int days = (y-1) * 360 + (m-1) * 30 + d + n - 1;
    
    int newy = days / 360 + 1;
    int newm = (days % 360) /30 + 1;
    int newd = days % 30 + 1;
    
    printf("%04d-%02d-%02d", newy, newm, newd);
    
    return 0;
}