while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    a = []
    for i in range(m):
        a.append(list(map(int, input().split())))
    a.sort()
    chk = [False] * (n+1)
    chk[1] = True
    for i in range(m):
        if chk[a[i][1]]:
            chk[a[i][2]] = True
    s = 0
    for i in range(1, n+1):
        if chk[i]: s += 1
    print(s)