n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(input()))
for _ in range(n):
    for i in range(n-1, 0, -1):
        for j in range(m):
            if a[i][j] == '.' and a[i-1][j] == 'o':
                a[i][j], a[i-1][j] = a[i-1][j], a[i][j]
for i in range(n):
    print(''.join(a[i]))