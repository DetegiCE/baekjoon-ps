n, m = map(int, input().split())
a = []
b = []
for i in range(n):
    a.append(list(map(int, input().split())))
for i in range((n)//2):
    b.append([])
    for j in range((m)//2):
        b[-1].append({a[i][j]:1})
# print(b)
for i in range((n)//2):
    for j in range((m)//2):
        if a[i][m-1-j] not in b[i][j]:
            b[i][j][a[i][m-1-j]] = 0
        b[i][j][a[i][m-1-j]] += 1
for i in range((n)//2):
    for j in range((m)//2):
        if a[n-1-i][j] not in b[i][j]:
            b[i][j][a[n-1-i][j]] = 0
        b[i][j][a[n-1-i][j]] += 1
for i in range((n)//2):
    for j in range((m)//2):
        if a[n-1-i][m-1-j] not in b[i][j]:
            b[i][j][a[n-1-i][m-1-j]] = 0
        b[i][j][a[n-1-i][m-1-j]] += 1
# print(b)
s = 0
for i in range((n)//2):
    for j in range((m)//2):
        s += 4-max(b[i][j].values())
if n % 2 == 1:
    for i in range(m//2):
        if a[n//2][i] != a[n//2][m-i-1]:
            s += 1
if m % 2 == 1:
    for i in range(n//2):
        if a[i][m//2] != a[n-i-1][m//2]:
            s += 1
print(s)
