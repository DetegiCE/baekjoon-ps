dx=[-1,0,1,0]
dy=[0,-1,0,1]
a = []
for i in range(100):
    b = []
    for j in range(100):
        b.append(0)
    a.append(b)
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    for j in range(x, x+10):
        for k in range(y, y+10):
            a[j][k] = 1
c = 0
for i in range(100):
    for j in range(100):
        if a[i][j] == 0:
            continue
        for k in range(4):
            nx = i+dx[k]
            ny = j+dy[k]
            if nx < 0 or nx >= 100 or ny < 0 or ny >= 100 or a[nx][ny] == 0:
                c += 1
print(c)