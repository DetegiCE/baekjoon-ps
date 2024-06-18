n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
garo = []
for i in range(n):
    garo.append(a[i].count('#'))
sero = []
for i in range(m):
    cnt = 0
    for j in range(n):
        if a[j][i] == '#':
            cnt += 1
    sero.append(cnt)
garomax = max(garo)
seromax = max(sero)
if garo.count(garomax) == 2:
    midx = sero.index(seromax)
    m2idx = sero.index(seromax-1)
    if midx > m2idx: print('LEFT')
    else: print('RIGHT')
else:
    midx = garo.index(garomax)
    m2idx = garo.index(garomax-1)
    if midx > m2idx: print('UP')
    else: print('DOWN')
    
