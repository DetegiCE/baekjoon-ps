n, k = map(int, input().split())
a = list(map(int, input().split()))
s = 0
c = 0
for i in range(n):
    s += a[i]
    if s >= k:
        c += 1
        s = 0
d = 0
s = 0
for i in range(n-1, -1, -1):
    s += a[i]
    if s >= k:
        d += 1
        s = 0
print(max(c, d))
