n, h, w = map(int, input().split())
s = []
for i in range(h):
    s.append(list(input()))
for k in range(n):
    q = 0
    o = ''
    for i in range(h):
        for j in range(w*k, w*(k+1)):
            if s[i][j] == '?':
                q = 1
            else:
                o = s[i][j]
    if o != '':
        print(o, end='')
    else:
        print('?', end='')
