from sys import stdin
input = stdin.readline

while True:
    a, b, c, d = map(float, input().split())
    a, b, c = int(a), int(b), int(c)
    if a == 0:
        break
    m = d/1200
    e = 1
    bal = 0
    if a*m >= b: e = 0
    elif d < 0.001:
        if b * c * 12 < a:
            e = 0
    else:
        bal = (a-b/m) * ((m+1)**(c*12)) + b/m
        if bal > 0: e = 0
    if e == 1:
        print('YES')
    else:
        print('NO')
