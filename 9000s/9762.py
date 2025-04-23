t = int(input())
for _ in range(t):
    n = int(input())
    a = [0]*(n//2) + list(map(int, input().split()))
    for i in range(n-1, 1, -2):
        idx1 = i
        idx2 = i-1
        idx3 = idx2//2
        m = min(a[idx1], a[idx2])
        a[idx3] += m
        a[idx1] -= m
        a[idx2] -= m
    print(sum(a))