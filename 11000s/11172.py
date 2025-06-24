def chk(p1, p2):
    x1, y1, r1 = p1[1:]
    x2, y2, r2 = p2[1:]
    return (x1-x2)**2+(y1-y2)**2 < (r1+r2)**2

for _ in range(int(input())):
    n = int(input())
    a = []
    for i in range(n):
        a.append(input().split())
        a[-1][1:] = list(map(int, a[-1][1:]))
    b = []
    for i in range(n):
        b.append(0)
    for i in range(n):
        for j in range(i+1, n):
            if chk(a[i], a[j]):
                b[i] += 1
                b[j] += 1
    mx = max(b)
    mxcnt = 0
    for i in range(n):
        if b[i] == mx: mxcnt += 1
    if mxcnt == 1:
        for i in range(n):
            if b[i] == mx:
                print(a[i][0])
                break
    else: print('TIE')