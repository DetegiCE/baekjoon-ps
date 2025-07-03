e = 0
while True:
    n, a, b = map(int, input().split())
    if n == 0:
        break
    e += 1
    print('Case', e)
    c = list(map(int, input().split()))
    d = []
    for i in range(n):
        d.append((c[i], i+1))
    d.sort()
    g = []
    h = []
    for i in range(a):
        g.append(d[i][1])
    g.sort()
    print(*g)
    for i in range(-1, -b-1, -1):
        h.append(d[i][1])
    h.sort(reverse=True)
    print(*h)