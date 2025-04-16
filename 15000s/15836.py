tc = 1
while True:
    m, n, p, q = map(int, input().split())
    if m == 0 and n == 0 and p == 0 and q == 0: break
    print(f'Case #{tc}:')
    tc += 1
    a = []
    b = []
    for i in range(m):
        a.append(list(map(int, input().split())))
    for i in range(p):
        b.append(list(map(int, input().split())))
    if n != p:
        print('undefined')
        continue
    for i in range(m):
        print('|', end=' ')
        for j in range(q):
            s = 0
            for k in range(n):
                s += a[i][k] * b[k][j]
            print(s, end=' ')
        print('|')