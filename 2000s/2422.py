n, m = map(int, input().split())
d = dict()
for i in range(1, n+1):
    d[i] = []
for _ in range(m):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    d[a].append(b)
c = 0
for i in range(1, n+1):
    for j in range(i+1, n+1):
        if j in d[i]: continue
        for k in range(j+1, n+1):
            if k in d[i]: continue
            if k in d[j]: continue
            c += 1
print(c)
