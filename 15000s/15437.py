r, c = map(int, input().split())
y, x = 0, 0
a = [input() for _ in range(r)]
b = 0
v = []
for i in range(r):
    w = []
    for j in range(c):
        w.append(0)
    v.append(w)
while a[y][x] != 'T':
    if v[y][x] == 1:
        print('Lost')
        exit(0)
    b += 1
    v[y][x] = 1
    if a[y][x] == 'E':
        x += 1
    elif a[y][x] == 'W':
        x -= 1
    elif a[y][x] == 'S':
        y += 1
    elif a[y][x] == 'N':
        y -= 1
    if not 0 <= y < r:
        print('Out')
        exit(0)
    if not 0 <= x < c:
        print('Out')
        exit(0)
print(b)