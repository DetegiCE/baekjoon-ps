#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

#define pb(A) push_back(A)

int n;
int sum = 0;
int subsum;
vector<int> v;
vector<int> factor;
int num[51];
vector<int> ans[50010];
bool flag;

void finder(int idx, int cursum, int group) {
    // printf(" -- finder (%d, %d, %d)\n", idx, cursum, group);
    if(flag) return;
    if(group == sum / subsum) {
        flag = true;
        return;
    } 
    if(cursum == subsum) {
        finder(0, 0, group+1);
    }
    else {
        for(int i=idx ; i<n ; i++) {
            if(cursum + v[i] > subsum) continue;
            if(num[i]) continue;
            num[i] = group + 1;
            finder(i+1, cursum + v[i], group);
            if(flag) return;
            num[i] = 0;
        }
    }
}

void reset() {
    flag = false;
    for(int i=0 ; i<n ; i++) {
        num[i] = 0;
    }
}

bool check() {
    if(v[0] > subsum) return false;
    // for(int i=0 ; i<v.size() ; i++)  printf("%d ", num[i]); puts("");
    reset();

    int group = 0;
    for(int i=0 ; i<n ; i++) {
        if(v[i] == subsum) {
            num[i] = ++group;
        }
    }
    for(int i=0 ; i<n ; i++) {
        if(num[i] == 0) {
            for(int j=i+1 ; j<n ; j++) {
                if(num[j] == 0 && v[i] + v[j] == subsum) {
                    num[i] = ++group;
                    num[j] = group;
                    break;
                }
            }
        }
    }

    finder(0, 0, group);
    return flag;
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        int t;
        scanf("%d", &t);
        sum += t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());

    factor.pb(1), factor.pb(sum);

    int i;
    for(i=2 ; i*i < sum ; i++) {
        if (sum % i == 0) {
            factor.pb(i);
            factor.pb(sum/i);
        }
    }
    if(i * i == sum) factor.pb(i);
    sort(factor.begin(), factor.end());
    for(int i=0 ; i<factor.size() ; i++) {
        subsum = factor[i];
        if(check()) {
            printf("%d\n", subsum);
            for(int j=0 ; j<n ; j++) {
                ans[num[j]].pb(v[j]);
            }
            for(int j=1 ; j<=sum/subsum ; j++) {
                for(int k=0 ; k<ans[j].size() ; k++) {
                    printf("%d ", ans[j][k]);
                }
                puts("");
            }
            return 0;
        }
    }
}