#include <cstdio>
#define MAX(A, B) (A > B ? A : B)

int n, mx;
int arr[201], brr[201];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        brr[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && brr[j] + 1 > brr[i]) {
                brr[i] = brr[j] + 1;
            }
        }
        mx = MAX(mx, brr[i]);
    }
    printf("%d", n - mx);
}