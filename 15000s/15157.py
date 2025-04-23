n = int(input())
a = list(map(int, input().split()))
mn = 1e18
for i in range(n):
    mn = min(a[i], mn + 1)
    print(mn, end=' ')