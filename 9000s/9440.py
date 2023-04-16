while True:
    a = list(map(int, input().split()))
    if len(a) == 1:
        break
    b = sorted(a[1:])
    p, q = "", ""
    zcnt = 0
    c = 0
    for i in b:
        if i == 0:
            zcnt += 1
            continue
        if c % 2 == 0:
            p += str(i)
            c += 1
        else:
            q += str(i)
            c += 1
    for i in range(zcnt):
        if len(p) == len(q):
            p = p[0] + '0' + p[1:]
        else:
            q = q[0] + '0' + q[1:]
    print(int(p) + int(q))
