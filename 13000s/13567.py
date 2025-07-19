m, n = map(int, input().split())
x, y = 0, 0
d = 0 # E N W S
for _ in range(n):
    a, b = input().split()
    b = int(b)
    if a == 'MOVE':
        if d == 0:
            if x + b <= m:
                x += b
            else:
                print(-1); exit(0)
        elif d == 1:
            if y + b <= m:
                y += b
            else:
                print(-1); exit(0)
        elif d == 2:
            if x - b >= 0:
                x -= b
            else:
                print(-1); exit(0)
        else:
            if y - b >= 0:
                y -= b
            else:
                print(-1); exit(0)
    else:
        if b == 0:
            if d == 0: d = 1
            elif d == 1: d = 2
            elif d == 2: d = 3
            else: d = 0
        else:
            if d == 0: d = 3
            elif d == 1: d = 0
            elif d == 2: d = 1
            else: d = 2
print(x, y)