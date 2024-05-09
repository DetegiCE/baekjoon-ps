n = int(input())
a = list(map(int, input().split()))
ans = 1e18
t = a[0]
for i in range(1, n):
    ans = min(ans, abs(a[i] - t))
    t = a[i]
print(ans)
