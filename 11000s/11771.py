n = int(input())
a = []
for i in range(n):
    a.append(list(input()))
b = input()

dcnt = 0
for i in range(n):
    for j in range(n):
        if a[i][j] == '.':
            dcnt += 1

if len(b) != n*n or dcnt != n*n//4:
    print('invalid grille')
    exit(0)

c = []
t = []
for i in range(n):
    cl = []
    tl = []
    for j in range(n):
        cl.append('X')
        tl.append('X')
    c.append(cl)
    t.append(tl)
    
cnt = 0
for lp in range(4):
    for i in range(n):
        for j in range(n):
            if a[i][j] == '.':
                c[i][j] = b[cnt]
                cnt += 1
    for i in range(n):
        for j in range(n):
            t[j][n-1-i] = a[i][j]
    for i in range(n):
        for j in range(n):
            a[i][j] = t[i][j]

s = ''
for i in range(n):
    s += ''.join(c[i])
            
if 'X' in s:
    print('invalid grille')
else:
    print(s)
            
            
    
    
