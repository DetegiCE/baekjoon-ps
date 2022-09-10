for i in range(int(input())):
    print(f'Data Set {i+1}:')
    n, m = input().split()
    n, m = int(n), float(m)
    a = []
    b = []
    c = []
    t = [0 for _ in range(n+1)]
    for _ in range(n):
        d, e, f = map(float, input().split())
        a.append(d)
        b.append(e)
        c.append(f)
    t[n] = m
    for i in range(n-1, -1, -1):
        t[i] = t[i+1] + a[i]
    v = s = 0
    for i in range(n):
        s += v * b[i] + 0.5 * b[i] * b[i] * (c[i] / t[i] - 9.81)
        v += b[i] * (c[i] / t[i] - 9.81)
    print("%.2f" % s)
    