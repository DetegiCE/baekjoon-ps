n = int(input())
a = []
b = []
for i in range(n):
    a.append(input().split())
    nl = [[] for j in range(n)]
    b.append(nl)
b[0][0].append(int(a[0][0]))
for i in range(n):
    for j in range(n):
        if (i + j) == 0:
            continue
        if (i + j) % 2 == 1:
            continue
        if i - 2 >= 0:
            for k in b[i-2][j]:
                b[i][j].append(eval(f'{k}{a[i-1][j]}{a[i][j]}'))
        if j - 2 >= 0:
            for k in b[i][j-2]:
                b[i][j].append(eval(f'{k}{a[i][j-1]}{a[i][j]}'))
        if i - 1 >= 0 and j - 1 >= 0:
            for k in b[i-1][j-1]:
                b[i][j].append(eval(f'{k}{a[i][j-1]}{a[i][j]}'))
                b[i][j].append(eval(f'{k}{a[i-1][j]}{a[i][j]}'))
print(max(b[n-1][n-1]), min(b[n-1][n-1]))
