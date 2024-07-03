#include <iostream>
using namespace std;

int n, k;
int a[10001];

void print(int p, int q) {
    cout << min(p, q) << ' ' << max(p, q);
}

int part(int p, int r) {
    int x = a[r];
    int i = p - 1;
    for(int j=p ; j<=r-1 ; j++) {
        if(a[j] <= x) {
            i++;
            swap(a[i], a[j]);
            k--;
            if(!k) {
                print(a[i], a[j]);
                exit(0);
            }
        }
    }
    if(i+1 != r) {
        swap(a[i+1], a[r]);
        k--;
        if(!k) {
            print(a[i+1], a[r]);
            exit(0);
        }
    }
    return i+1;
}

void qs(int p, int r) {
    if(p < r) {
        int q = part(p, r);
        qs(p, q-1);
        qs(q+1, r);
    }
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i];
    }
    qs(1, n);
    cout << -1;
}
