n = int(input())
m = []
q = []
for i in range(n):
    m.append(list(input()))
    p = []
    for j in range(n):
        p.append(0)
    q.append(p)
for i in range(n):
    for j in range(n):
        if m[i][j] != '.':
            q[i][j] = '*'
        else:
            dy=[-1,-1,-1,0,0,1,1,1]
            dx=[-1,0,1,-1,1,-1,0,1]
            s = 0
            for k in range(8):
                if 0<=i+dy[k]<n and 0<=j+dx[k]<n and m[i+dy[k]][j+dx[k]] != '.':
                    s += int(m[i+dy[k]][j+dx[k]])
            if s >= 10:
                q[i][j] = 'M'
            else:
                q[i][j] = str(s)
for i in range(n):
    print(''.join(q[i]))
