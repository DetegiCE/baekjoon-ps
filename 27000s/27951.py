n = int(input())
a = list(map(int, input().split()))
u, d = map(int, input().split())
b = []
flg = 0
for i in a:
    if i == 1:
        if u > 0:
            b.append('U')
            u -= 1
        else:
            b.append('X')
            flg = 1
    elif i == 2:
        if d > 0:
            b.append('D')
            d -= 1
        else:
            b.append('X')
            flg = 1
    else:
        b.append('!')
for i in range(n):
    if b[i] == '!':
        if u > 0:
            b[i] = 'U'
            u -= 1
        elif d > 0:
            b[i] = 'D'
            d -= 1
if flg == 0:
    print('YES')
    print(''.join(b))
else:
    print('NO')
