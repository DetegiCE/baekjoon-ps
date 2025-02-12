#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;

void heapify(int k, int n) {
    int left = 2 * k;
    int right = 2 * k + 1;
    int smaller = -1;
    if(right <= n) {
        if(A[left] < A[right]) {
            smaller = left;
        }
        else smaller = right;
    }
    else if(left <= n) {
        smaller = left;
    }
    else return;

    if(A[smaller] < A[k]) {
        int tmp = A[k];
        A[k] = A[smaller];
        A[smaller] = tmp;
        K--;
        if(K == 0) {
            for(int i=1 ; i<=N ; i++) {
                cout << A[i] << ' ';
            }
            exit(0);
        }
        heapify(smaller, n);
    }
}

void build_min_heap(int n) {
    for(int i=n/2 ; i>=1 ; i--) {
        heapify(i, n);
    }
}

void heap_sort() {
    build_min_heap(N);
    for(int i=N ; i>=2 ; i--) {
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        K--;
        if(K == 0) {
            for(int j=1 ; j<=N ; j++) {
                cout << A[j] << ' ';
            }
            exit(0);
        }
        heapify(1, i-1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    A.push_back(-1);
    for(int i=0 ; i<N ; i++) {
        int t;
        cin >> t;
        A.push_back(t);
    }

    heap_sort();    
    cout << -1;
}