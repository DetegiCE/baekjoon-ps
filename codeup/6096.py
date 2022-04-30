a = list()
for i in range(21):
    a.append(list())
    for j in range(21):
        a[i].append(0)
for i in range(1, 20):
    b = list(map(int, input().split()))
    for j in range(1, 20):
        a[i][j] = b[j-1]
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    for j in range(1, 20):
        if a[x][j] == 0: a[x][j] = 1
        else: a[x][j] = 0
    for j in range(1, 20):
        if a[j][y] == 0: a[j][y] = 1
        else: a[j][y] = 0
for i in range(1, 20):
    for j in range(1, 20):
        print(a[i][j], end=' ')
    print()
