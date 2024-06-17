n = int(input())
a = []
for i in range(n):
    s, t = map(int, input().split())
    a.append([-s, t])
a.sort()
c = 0
for i in range(5, n):
    if a[i][0] == a[4][0]:
        c += 1
print(c)
