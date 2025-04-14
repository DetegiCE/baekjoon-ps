n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
for i in range(n):
    for j in range(m):
        c = 0
        for k in range(n):
            if i == k: continue
            chk = True
            for l in range(25):
                if a[i][l] != a[k][l] and b[j][l] != a[k][l]:
                    chk = False
            if chk: c += 1
        for k in range(m):
            if j == k: continue
            chk = True
            for l in range(25):
                if a[i][l] != b[k][l] and b[j][l] != b[k][l]:
                    chk = False
            if chk: c += 1
        print(c, end=' ')
    print()