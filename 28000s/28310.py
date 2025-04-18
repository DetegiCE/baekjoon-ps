from math import gcd as g
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    fr = [[0, 1] for _ in range(n)]
    fradd = lambda x, y: [x[0] * y[1] + x[1] * y[0], x[1] * y[1]]
    for i in range(m):
        a = list(map(int, input().split()))
        b = a[0]
        a = a[1:]
        for j in range(n):
            fr[j] = fradd(fr[j], [a[j], b])
    fr.sort(key = lambda x: x[0] / x[1])
    p = fr[-1]
    q = fr[0]
    dn = p[1] * q[1]
    up = p[0] * q[1] - p[1] * q[0]
    gc = g(dn, up)
    dn //= gc
    up //= gc
    if dn == 1: print(up)
    else: print(f'{up}/{dn}')