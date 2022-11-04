#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;

int n, mx = -1;

int mappmax(vvi mapp) {
    int mxv = -1;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            mxv = max(mxv, mapp[i][j]);
        }
    }
    return mxv;
}

vvi up(vvi mapp) {
    bool vis[23][23];
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            vis[i][j] = false;
        }
    }
    for(int k=0 ; k<n ; k++)
        for(int i=1 ; i<=n-1 ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == 0 && mapp[i+1][j] != 0) {
                    mapp[i][j] = mapp[i+1][j];
                    mapp[i+1][j] = 0;
                    vis[i][j] = vis[i+1][j];
                    vis[i+1][j] = false;
                }
            }
        }
        for(int i=1 ; i<=n-1 ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == mapp[i+1][j] && !vis[i][j] && !vis[i+1][j]) {
                    mapp[i][j] += mapp[i+1][j];
                    mapp[i+1][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
    
    for(int k=0 ; k<n ; k++)
        for(int i=1 ; i<=n-1 ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == 0 && mapp[i+1][j] != 0) {
                    mapp[i][j] = mapp[i+1][j];
                    mapp[i+1][j] = 0;
                    vis[i][j] = vis[i+1][j];
                    vis[i+1][j] = false;
                }
            }
        }
    return mapp;
}

vvi down(vvi mapp) {
    bool vis[23][23];
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            vis[i][j] = false;
        }
    }
    for(int k=0 ; k<n ; k++)
        for(int i=n ; i>=2 ; i--) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == 0 && mapp[i-1][j] != 0) {
                    mapp[i][j] = mapp[i-1][j];
                    mapp[i-1][j] = 0;
                    vis[i][j] = vis[i-1][j];
                    vis[i-1][j] = false;
                }
            }
        }
        for(int i=n ; i>=2 ; i--) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == mapp[i-1][j] && !vis[i][j] && !vis[i-1][j]) {
                    mapp[i][j] += mapp[i-1][j];
                    mapp[i-1][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
    for(int k=0 ; k<n ; k++)
        for(int i=n ; i>=2 ; i--) {
            for(int j=1 ; j<=n ; j++) {
                if(mapp[i][j] == 0 && mapp[i-1][j] != 0) {
                    mapp[i][j] = mapp[i-1][j];
                    mapp[i-1][j] = 0;
                    vis[i][j] = vis[i-1][j];
                    vis[i-1][j] = false;
                }
            }
        }
    return mapp;
}

vvi left(vvi mapp) {
    bool vis[23][23];
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            vis[i][j] = false;
        }
    }
    for(int k=0 ; k<n ; k++)
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n-1 ; j++) {
                if(mapp[i][j] == 0 && mapp[i][j+1] != 0) {
                    mapp[i][j] = mapp[i][j+1];
                    mapp[i][j+1] = 0;
                    vis[i][j] = vis[i][j+1];
                    vis[i][j+1] = false;
                }
            }
        }
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n-1 ; j++) {
                if(mapp[i][j] == mapp[i][j+1] && !vis[i][j] && !vis[i][j+1]) {
                    mapp[i][j] += mapp[i][j+1];
                    mapp[i][j+1] = 0;
                    vis[i][j] = true;
                }
            }
        }
    for(int k=0 ; k<n ; k++)
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n-1 ; j++) {
                if(mapp[i][j] == 0 && mapp[i][j+1] != 0) {
                    mapp[i][j] = mapp[i][j+1];
                    mapp[i][j+1] = 0;
                    vis[i][j] = vis[i][j+1];
                    vis[i][j+1] = false;
                }
            }
        }
    return mapp;
}

vvi right(vvi mapp) {
    bool vis[23][23];
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            vis[i][j] = false;
        }
    }
    for(int k=1 ; k<=n ; k++) 
        for(int i=1 ; i<=n ; i++) {
            for(int j=n ; j>=2 ; j--) {
                if(mapp[i][j] == 0 && mapp[i][j-1] != 0) {
                    mapp[i][j] = mapp[i][j-1];
                    mapp[i][j-1] = 0;
                    vis[i][j] = vis[i][j-1];
                    vis[i][j-1] = false;
                }
            }
        }
        for(int i=1 ; i<=n ; i++) {
            for(int j=n ; j>=2 ; j--) {
                if(mapp[i][j] == mapp[i][j-1] && !vis[i][j] && !vis[i][j-1]) {
                    mapp[i][j] += mapp[i][j-1];
                    mapp[i][j-1] = 0;
                    vis[i][j] = true;
                }
            }
        }
    for(int k=1 ; k<=n ; k++) 
        for(int i=1 ; i<=n ; i++) {
            for(int j=n ; j>=2 ; j--) {
                if(mapp[i][j] == 0 && mapp[i][j-1] != 0) {
                    mapp[i][j] = mapp[i][j-1];
                    mapp[i][j-1] = 0;
                    vis[i][j] = vis[i][j-1];
                    vis[i][j-1] = false;
                }
            }
        }
    return mapp;
}

void go(vvi mapp, int cnt) {
    // cout << "go " << cnt << '\n';
    if(cnt == 5) {
        int mxv = mappmax(mapp);
        mx = max(mx, mxv);
        return;
    }
    go(up(mapp), cnt+1);
    go(down(mapp), cnt+1);
    go(left(mapp), cnt+1);
    go(right(mapp), cnt+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vvi mapp;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    mapp.push_back(v);
    for(int i=1 ; i<=n ; i++) {
        vector<int> v;
        v.push_back(0);
        for(int j=1 ; j<=n ; j++) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        mapp.push_back(v);
    }
    go(mapp, 0);
    cout << mx;
}
