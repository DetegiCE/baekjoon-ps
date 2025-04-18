def f(n):
    if n % 10 in [0, 5]: return n
    elif n % 10 in [1, 6]: return n-1
    elif n % 10 in [9, 4]: return n+1
    else: return n

for _ in range(int(input())):
    n, m = map(int, input().split())
    d = dict()
    for _ in range(n):
        p, q, r, s = input().split()
        d[p] = [int(q), int(r), int(s)]
    b = 100 // m
    for _ in range(m):
        p, q, r = input().split()
        if q[0] == 's': print(p, f(d[r][0] + b))
        if q[0] == 'm': print(p, f(d[r][1] + b))
        if q[0] == 'l': print(p, f(d[r][2] + b))