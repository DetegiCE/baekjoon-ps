from sys import stdin
input = stdin.readline

n = int(input())
for _ in range(n):
    a = []
    for i in range(5):
        a.append(input().strip())
    aw = 0
    bw = 0
    for i in range(5):
        if 'AAA' in a[i]:
            aw = 1
        if 'BBB' in a[i]:
            bw = 1
    for i in range(3):
        for j in range(5):
            if a[i][j] == a[i+1][j] == a[i+2][j] == 'A':
                aw = 1
            if a[i][j] == a[i+1][j] == a[i+2][j] == 'B':
                bw = 1
    for i in range(3):
        for j in range(3):
            if a[i][j] == a[i+1][j+1] == a[i+2][j+2] == 'A': aw = 1
            if a[i][j] == a[i+1][j+1] == a[i+2][j+2] == 'B': bw = 1
    for i in range(3):
        for j in range(2, 5):
            if a[i][j] == a[i+1][j-1] == a[i+2][j-2] == 'A': aw = 1
            if a[i][j] == a[i+1][j-1] == a[i+2][j-2] == 'B': bw = 1
    if aw == bw:
        print('draw')
    elif aw == 1:
        print('A wins')
    else:
        print('B wins')
