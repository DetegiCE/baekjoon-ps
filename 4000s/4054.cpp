#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int ii=1 ;; ii++) {
        int n;
        string s;
        cin >> n;
        if(n == 0) break;
        int zerocount = 0;

        int center = 0, turn = 0;
        vector<int> chips;
        cin >> s;
        for(int i=0 ; i<n ; i++) chips.push_back(3);

        int cancelflag = 0;
        for(int i=0 ; i<s.length() ; i++) {
            // printf("%d %d %d\n", chips[0], chips[1], chips[2]);
            int cnt = min(chips[turn], 3);
            if(i+cnt-1 >= s.length()) break;

            for(int j=0 ; j<cnt ; j++) {
                if(s[i+j] == 'L') {
                    chips[(turn+n+1)%n]++;
                    if(chips[(turn+n+1)%n] == 1) zerocount--;
                    chips[turn]--;
                }
                if(s[i+j] == 'R') {
                    chips[(turn+n-1)%n]++;
                    if(chips[(turn+n-1)%n] == 1) zerocount--;
                    chips[turn]--;
                }
                if(s[i+j] == 'C') {
                    center++;
                    chips[turn]--;
                }
            }
            if(cnt > 0 && chips[turn] == 0) zerocount++;
            i += (cnt-1);

            if(zerocount == n-1) break;

            if(cancelflag == 0) {
                turn++;
                turn %= n;
            }
        }
        while(chips[turn] == 0) {
            turn++;
            turn%=n;
        }

        printf("Game %d:\n", ii);
        for(int i=0 ; i<n ; i++) {
            printf("Player %d:%d", i+1, chips[i]);
            if(zerocount == n-1 && chips[i] != 0) {
                printf("(W)\n");
            }
            else if(zerocount != n-1 && turn == i) {
                printf("(*)\n");
            }
            else {
                puts("");
            }
        }
        printf("Center:%d\n\n", center);
    }

}