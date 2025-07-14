for t in range(int(input())):
    print(f'Case #{t+1}: ', end='')
    a = list(map(int, input().split()))
    n = a[0]
    p = a[1:]
    d = [p[:]]
    for i in range(1, n+1):
        c = []
        pd = d[i-1]
        for j in range(len(pd) - 1):
            c.append(pd[j+1] - pd[j])
        d.append(c)
    cd = d[n][0]
    cv = p[:]
    for i in range(n+1, 51):
        if len(d[n]) <= i - n:
            d[n].append(cd)
        for j in range(n-1, -1, -1):
            if len(d[j]) <= i - j:
                nd = d[j][-1] + d[j+1][-1]
                d[j].append(nd)
        cv.append(d[0][-1])
    print(cv[50])
