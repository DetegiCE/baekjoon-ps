n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = 0
dy = [-1,-1,-1,0,0,1,1,1]
dx = [-1,0,1,-1,1,-1,0,1]
inchk = lambda y, x: 0 <= y < n and 0 <= x < m
for i in range(65, 91):
    for j in range(65, 91):
        if i == j or i == 77 or j == 79: continue
        mx = 0
        for y in range(n):
            for x in range(m):
                if ord(a[y][x]) == i:
                    for k in range(8):
                        ny = y + dy[k]
                        nx = x + dx[k]
                        ny2 = y + dy[k] * 2
                        nx2 = x + dx[k] * 2
                        if inchk(ny,nx) and inchk(ny2,nx2) and ord(a[ny][nx]) == j and ord(a[ny2][nx2]) == j:
                            mx += 1
        b = max(b, mx)
print(b)