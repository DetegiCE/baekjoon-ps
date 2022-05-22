#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX(A,B) (A>B?A:B)

typedef long long ll;

int n, k, d;
int totalgo[31];
ll ans;
ll eff;

struct Student {
    int algo, skill;
    vector<int> algos;
    bool operator < (const Student &s) const {
        return skill < s.skill;
    }
};

vector<Student> student;

int main()
{
    scanf("%d %d %d", &n, &k, &d);
    for(int i=0 ; i<n ; i++) {
        int aa, bb;
        vector<int> cc;
        scanf("%d %d", &aa, &bb);
        for(int j=0 ; j<aa ; j++) {
            int t;
            scanf("%d", &t);
            cc.push_back(t);
        }
        Student nst = {aa, bb, cc};
        student.push_back(nst);
    }
    sort(student.begin(), student.end());

    for(int i=0 ; i<student[0].algos.size() ; i++) {
        totalgo[student[0].algos[i]]++;
    }

    ll left = 0, right = 1;
    bool isRightUp = true;
    while(right < n) {
        if(isRightUp) {
            for(int i=0 ; i<student[right].algos.size() ; i++) {
                totalgo[student[right].algos[i]]++;
            }
        }
        else {
            for(int i=0 ; i<student[left-1].algos.size() ; i++) {
                totalgo[student[left-1].algos[i]]--;
            }
        }

        if(student[right].skill - student[left].skill > d) {
            isRightUp = false;
            left++;
        }
        else {
            ll orAlgo = 0;
            ll andAlgo = 0;
            for(int i=1 ; i<=k ; i++) {
                if(totalgo[i] > 0) orAlgo++;
                if(totalgo[i] == right-left+1) andAlgo++;
            }
            eff = (orAlgo-andAlgo)*(right-left+1);
            ans = MAX(ans, eff);
            isRightUp = true;
            right++;
        }
    }
    printf("%lld\n", ans);
}