r, c = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]
dx = [-1,-1,-1,0,0,1,1,1]
dy = [-1,0,1,-1,1,-1,0,1]
mx = 0
for i in range(r):
    for j in range(c):
        if a[i][j] == 0: continue

        for k in range(8):
            nr = i + dx[k]
            nc = j + dy[k]
            if 0 <= nr < r and 0 <= nc < c and a[i][j] == a[nr][nc]:
                mx = max(mx, a[i][j])
print(mx)