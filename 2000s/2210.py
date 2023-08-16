a = []
s = set()
def dfs(y, x, cnt, v):
    global a
    if cnt == 5:
        s.add(v)
        return
    dy=[-1,0,1,0]
    dx=[0,-1,0,1]
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if 0<=ny<5 and 0<=nx<5:
            dfs(ny, nx, cnt+1, v*10+a[ny][nx])

for i in range(5):
    a.append(list(map(int, input().split())))
for i in range(5):
    for j in range(5):
        dfs(i, j, 0, a[i][j])
# print(s)
print(len(s))
