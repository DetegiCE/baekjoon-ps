n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
for i in range(m):
    for j in range(n-1, -1, -1):
        print(a[j][i], end='')
    print()
