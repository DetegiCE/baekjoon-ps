n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]
print(m)
for i in range(m):
    for j in range(n):
        print(a[(i+j)%m][j], end=' ')
    print()