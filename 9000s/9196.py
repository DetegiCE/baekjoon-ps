from sys import stdin
input = stdin.readline
a = [[] for _ in range(45105)]
for i in range(1, 151):
    for j in range(i+1, 151):
        a[i*i+j*j].append([i, j])
for i in range(45105):
    if len(a[i]) > 0:
        a[i].sort(key=lambda x: (x[0], x[1]))
while True:
    x, y = map(int, input().split())
    if x == 0 and y == 0:
        break
    c = x*x+y*y
    if a[c][-1][0] == x and a[c][-1][1] == y:
        for i in range(c+1, 45105):
            if len(a[i]) > 0:
                print(a[i][0][0], a[i][0][1])
                break
    else:
        for i in range(len(a[c])):
            if a[c][i][0] == x and a[c][i][1] == y:
                print(a[c][i+1][0], a[c][i+1][1])
                break
