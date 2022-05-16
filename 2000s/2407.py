a = [[1], [1,1], [1,2,1], [1,3,3,1]]
n, m = map(int, input().split())
for i in range(4, n+1):
    b = [1]
    for j in range(0, i-1):
        b.append(a[i-1][j]+a[i-1][j+1])
    b.append(1)
    a.append(b)
print(a[n][m])