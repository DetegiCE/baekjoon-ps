def r(n):
    if n - int(n) >= 0.5:
        return int(n) + 1
    else:
        return int(n)

n, m = map(int, input().split())
name = [[0, _, input()] for _ in range(n)]
name += [[0, n, "Invalid"]]
for i in range(m):
    cnt = 0
    b = input()
    for j in range(n):
        if b[j] == 'X': cnt += 1
    if cnt > 1 or cnt == 0:
        name[n][0] += 1
        continue
    for j in range(n):
        if b[j] == 'X':
            name[j][0] += 1
name.sort(key=lambda x: (-x[0], x[1]))
f = -1
for i in range(n+1):
    if name[i][2] == 'Invalid':
        f = i
        continue
    print(name[i][2], f'{r(name[i][0]/m*10000)/100:.2f}%')
print(name[f][2], f'{r(name[f][0]/m*10000)/100:.2f}%')