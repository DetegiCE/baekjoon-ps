n = int(input())
a = []
for _ in range(n):
    x, y = map(int, input().split())
    a.append([x, y, _+1])
a.sort()
for i in range(n-1):
    print(a[i][2], a[i+1][2])