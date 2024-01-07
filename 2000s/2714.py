def f(r, c, b):
    d = 'R'
    cy = 0
    cx = 0
    ret = ''
    for i in range(r*c):
        ret += b[cy][cx]
        b[cy][cx] = '2'
        if d == 'R':
            cx += 1
            if cx >= c or b[cy][cx] == '2':
                d = 'D'
                cx -= 1
                cy += 1
        elif d == 'D':
            cy += 1
            if cy >= r or b[cy][cx] == '2':
                d = 'L'
                cx -= 1
                cy -= 1
        elif d == 'L':
            cx -= 1
            if cx < 0 or b[cy][cx] == '2':
                d = 'U'
                cx += 1
                cy -= 1
        else:
            cy -= 1
            if cy < 0 or b[cy][cx] == '2':
                d = 'R'
                cx += 1
                cy += 1
    return ret
    
dv = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for _ in range(int(input())):
    r, c, m = input().split()
    r, c = int(r), int(c)
    a = []
    for i in range(r):
        a.append(list(m[i*c:(i+1)*c]))
    s = f(r, c, a)
    ca = ''
    for i in range(0, len(s), 5):
        try:
            w = s[i:i+5]
            wk = int(w, 2)
            ca += dv[wk]
        except:
            break
    print(ca.rstrip())
    
    
