n = int(input())
a = [[1 for _ in range(i)] for i in range(1, n + 2)]
for i in range(2, n+1):
    for j in range(1, i):
        a[i][j] = a[i-1][j-1] + a[i-1][j]
for i in range(n+1):
    v = a[n][i]
    if i == 0:
        print('a^' + str(n) + '+', end='')
    elif i == n:
        print('b^' + str(n))
    else:
        print(str(v) + '*' + 'a^' + str(n-i) + '*' + 'b^' + str(i) + '+', end='')