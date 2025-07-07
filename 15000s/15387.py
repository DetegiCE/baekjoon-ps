def chk(a):
    l = ['O', 'WO', 'WS', 'ES', 'MS', 'CS', 'IS', 'OS', 'SS']
    cnt = 0
    for i in l:
        if i in a:
            cnt += 1
    return +(cnt == 9)

def f():
    a = [input().split() for _ in range(9)]
    c1cnt = 0
    for i in range(9):
        b = []
        for j in range(9):
            b.append(a[i][j])
        c1cnt += chk(b)
        c = []
        for j in range(9):
            c.append(a[j][i])
        c1cnt += chk(c)
    for i in [0, 3, 6]:
        for j in [0, 3, 6]:
            d = []
            for k in range(3):
                for l in range(3):
                    d.append(a[i+k][j+l])
            c1cnt += chk(d)
    return c1cnt == 27

g = int(input())
for _ in range(g):
    if f(): print('all 3')
    else: print('not')