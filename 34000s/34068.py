n, m = map(int, input().split())
a = [0 for _ in range(n)]
for _ in range(m):
    b, c = map(int, input().split())
    a[b-1] += 1
a.sort()
d = 0
for i in range(1, n):
    if a[i-1] >= a[i]:
        e = (a[i-1] - a[i]) + 1
        a[i] += e
        d += e
print(d)