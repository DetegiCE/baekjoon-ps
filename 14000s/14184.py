while True:
    n = int(input())
    if n == 0:
        break
    d = dict()
    d1, d2, d3 = dict(), dict(), dict()
    for i in range(n):
        a = [int(j) for j in input().split()]
        s = a[0]
        for j in range(1, s+1):
            if a[j] not in d:
                d[a[j]] = 0
                d1[a[j]] = 0
                d2[a[j]] = 0
                d3[a[j]] = 0
        for j in range(1, s+1):
            if j == 1:
                d[a[j]] += 3
                d1[a[j]] += 1
            elif j == 2:
                d[a[j]] += 2
                d2[a[j]] += 1
            else:
                d[a[j]] += 1
                d3[a[j]] += 1
    
    mx = max(d.values())
    a = []
    for i in d:
        if d[i] == mx: a.append(i)
    if len(a) == 1:
        print(a[0])
        continue

    b = []
    for i in a:
        b.append(d1[i])
    b1 = []
    mx1 = max(b)
    for i in range(len(b)):
        if b[i] == mx1: b1.append(a[i])
    if len(b1) == 1:
        print(b1[0])
        continue

    c = []
    for i in b1:
        c.append(d2[i])
    b2 = []
    mx2 = max(c)
    for i in range(len(c)):
        if c[i] == mx2: b2.append(b1[i])
    if len(b2) == 1:
        print(b2[0])
        continue
    
    e = []
    for i in b2:
        e.append(d3[i])
    b3 = []
    mx3 = max(e)
    for i in range(len(e)):
        if e[i] == mx3: b3.append(b2[i])
    if len(b3) == 1:
        print(b3[0])
        continue
    b3.sort()
    print(*b3)