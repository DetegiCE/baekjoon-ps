r, c = map(int, input().split())
grid = []
for i in range(r):
    grid.append(list(map(int, input().split())))
if r % 2 == 1:
    for i in range(r):
        if i == r-1:
            print('R' * (c-1))
        elif i % 2 == 0:
            print('R' * (c-1) + 'D', end='')
        else:
            print('L' * (c-1) + 'D', end='')
    exit(0)
if c % 2 == 1:
    for i in range(c):
        if i == c-1:
            print('D' * (r-1))
        elif i % 2 == 0:
            print('D' * (r-1) + 'R', end='')
        else:
            print('U' * (r-1) + 'R', end='')
    exit(0)
mny, mnx, mnv = -1, -1, 1001
for i in range(r):
    for j in range(c):
        if (i+j) % 2 == 1:
            if mnv > grid[i][j]:
                mnv = grid[i][j]
                mny = i
                mnx = j

for i in range(mnx//2):
    print('D' * (r-1) + 'R', end='')
    print('U' * (r-1) + 'R', end='')
    
if mnx % 2 == 0:
    for i in range(mny//2):
        print('RDLD', end='')
    print('RD', end='')
    if mny//2 != r//2 - 1:
        print('D', end='')
        for i in range(r//2 - mny//2 - 2):
            print('LDRD', end='')
        print('LDR', end='')
    if mnx // 2 < c//2 - 1:
        print('R', end='')
else:
    for i in range(mny//2):
        print('RDLD', end='')
    print('DR', end='')
    if mny//2 != r//2 - 1:
        print('D', end='')
        for i in range(r//2 - mny//2 - 2):
            print('LDRD', end='')
        print('LDR', end='')
    if mnx // 2 < c//2 - 1:
        print('R', end='')

for i in range(c//2 - mnx//2 - 1):
    print('U' * (r-1) + 'R', end='')
    print('D' * (r-1), end='')
    if i != c//2 - mnx//2 - 2:
        print('R', end='')
    
