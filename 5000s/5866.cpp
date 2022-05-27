#include<cstdio>
#include<vector>
using namespace std;

#define MIN(A,B) (A>B?B:A)
#define MAX(A,B) (A>B?A:B)

vector<int> one, two;
int pos, cnt;

int main()
{
    int b, e;
    scanf("%d %d", &b, &e);
    for(int i=0 ; i<b ; i++) {
        int a;
        char c;
        scanf("%d %c", &a, &c);
        if(c == 'L'){
            for(int j=pos-1 ; j>=pos-a ; j--)
                one.push_back(j);
            pos -= a;
        }
        else {
            for(int j=pos+1 ; j<=pos+a ; j++)
                one.push_back(j);
            pos += a;
        }
    }
    pos = 0;
    for(int i=0 ; i<e ; i++) {
        int a;
        char c;
        scanf("%d %c", &a, &c);
        if(c == 'L'){
            for(int j=pos-1 ; j>=pos-a ; j--)
                two.push_back(j);
            pos -= a;
        }
        else {
            for(int j=pos+1 ; j<=pos+a ; j++)
                two.push_back(j);
            pos += a;
        }
    }
    int k = 0;
    for(k=1 ; k<MIN(one.size(), two.size()) ; k++) {
        if((one[k] == two[k] && one[k-1] != two[k-1]) || (one[k-1]-two[k-1]==-1 && one[k]-two[k]==1) || (one[k-1]-two[k-1]==1 && one[k]-two[k]==-1)) {
            cnt++;
            //printf("%d\n", k);
        }
    }

    vector<int> *vp, *vq;
    if(one.size() < two.size()) {
        vp = &one;
        vq = &two;
    }
    else {
        vp = &two;
        vq = &one;
    }
    for(k=MIN(one.size(), two.size()) ; k<MAX(one.size(), two.size()) ; k++) {
        if((*vp)[MIN(one.size(), two.size())-1] == (*vq)[k]) {
            cnt++;
            // printf("A%d = (%d, %d)\n", k, (*vp)[MIN(one.size(), two.size())-1], (*vq)[k]);
        }
    }
    printf("%d", cnt);
}

/*
-1 -2 -3 -2 -1  0  1  2  1  2  3 
 1  2  3  4  3  2  1  0  1  2  3  4  3  2

*/