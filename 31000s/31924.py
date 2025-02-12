n = int(input())
if n < 5:
    print(0)
    exit(0)
a = [input() for _ in range(n)]

c = 0
for i in range(n):
    for j in range(n-4):
        if a[i][j:j+5] == 'MOBIS':
            c += 1
        if a[i][j:j+5] == 'SIBOM':
            c += 1
for i in range(n-4):
    for j in range(n):
        if a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j] + a[i+4][j] == 'MOBIS':
            c += 1
        if a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j] + a[i+4][j] == 'SIBOM':
            c += 1
for i in range(n-4):
    for j in range(n-4):
        if a[i][j] + a[i+1][j+1] + a[i+2][j+2] + a[i+3][j+3] + a[i+4][j+4] == 'MOBIS':
            c += 1
        if a[i][j] + a[i+1][j+1] + a[i+2][j+2] + a[i+3][j+3] + a[i+4][j+4] == 'SIBOM':
            c += 1
for i in range(4, n):
    for j in range(n-4):
        if a[i][j] + a[i-1][j+1] + a[i-2][j+2] + a[i-3][j+3] + a[i-4][j+4] == 'MOBIS':
            c += 1
        if a[i][j] + a[i-1][j+1] + a[i-2][j+2] + a[i-3][j+3] + a[i-4][j+4] == 'SIBOM':
            c += 1
print(c)