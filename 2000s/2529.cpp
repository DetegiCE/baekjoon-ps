//
// Created by RBK on 2022-01-31.
//

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> nums;
vector<char> comp;

bool check() {
    for(int i=0 ; i<n ; i++) {
        if(comp[i] == '>' && nums[i] > nums[i+1]) {
            continue;
        }
        if(comp[i] == '<' && nums[i] < nums[i+1]) {
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        char a;
        scanf(" %c", &a);
        comp.push_back(a);
    }
    for(int i=9 ; i>=9-n ; i--) {
        nums.push_back(i);
    }

    do {
        if(check()) {
            for(int i=0 ; i<=n ; i++) {
                printf("%d", nums[i]);
            }
            puts("");
            break;
        }
    } while(prev_permutation(nums.begin(), nums.end()));

    nums.clear();
    for(int i=0 ; i<=n ; i++) {
        nums.push_back(i);
    }

    do {
        if(check()) {
            for(int i=0 ; i<=n ; i++) {
                printf("%d", nums[i]);
            }
            break;
        }
    } while(next_permutation(nums.begin(), nums.end()));
}