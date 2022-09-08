n = m = r = 0
shells = 0
s = []
u = []
a = []

def shellify(lev: int):
    t = []
    di = 0
    sty = lev
    stx = lev
    t.append((sty, stx))
    stx += 1
    while sty != lev or stx != lev:
        t.append((sty, stx))
        if di == 0:
            if stx + 1 > m - lev - 1:
                sty += 1
                di = 1
            else:
                stx += 1
        elif di == 1:
            if sty + 1 > n - lev - 1:
                stx -= 1
                di = 2
            else:
                sty += 1
        elif di == 2:
            if stx - 1 < lev:
                sty -= 1
                di = 3
            else:
                stx -= 1
        else:
            sty -= 1
    s.append(t)

def unshellify(lev: int):
    for i in range(len(s[lev])):
        cury = s[lev][i][0]
        curx = s[lev][i][1]
        nxty = s[lev][(i+r)%len(s[lev])][0]
        nxtx = s[lev][(i+r)%len(s[lev])][1]
        u[cury][curx] = a[nxty][nxtx]
        
if __name__ == '__main__':
    n, m, r = map(int,input().split())
    shells = min(n, m) // 2
    for i in range(n):
        a.append(list(map(int,input().split())))
    for i in range(shells):
        shellify(i)
    u = [[0 for _ in range(m)] for __ in range(n)]
    for i in range(shells):
        unshellify(i)
    for i in range(n):
        for j in range(m):
            print(u[i][j], end=' ')
        print()