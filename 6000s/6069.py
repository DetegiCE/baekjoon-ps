n, m = map(int, input().split())
a = []
for i in range(n+1):
    a.append(0)
for i in range(m):
    p, q, r = map(int, input().split())
    if p == 0:
        for j in range(q, r+1):
            a[j] = 1-a[j]
    else:
        print(sum(a[q:r+1]))
