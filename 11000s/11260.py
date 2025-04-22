while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break
    a = []
    a.append(['.' for _ in range(m+2)])
    for i in range(n):
        a.append(['.'] + list(input()) + ['.'])
    a.append(['.' for _ in range(m+2)])
    c = 0
    dx = [-1,-1,-1,0,0,1,1,1]
    dy = [-1,0,1,-1,1,-1,0,1]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i][j] == '#' and all(a[i+dx[k]][j+dy[k]] == '.' for k in range(8)):
                c += 1
    print(c)