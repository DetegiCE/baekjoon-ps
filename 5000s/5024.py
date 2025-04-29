n, p = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
b = 1e18
for i in range(n):
    b = min(b, a[i] - p*(i+1))
print(a[0] - b)