n = int(input())
d = 1
c = 1
cx = 0
cy = 0
i = 0
while i < n:
    if d == 1:
        for j in range(c):
            cy += 1
            i += 1
            if i == n:
                break
    elif d == 2:
        for j in range(c):
            cx += 1
            i += 1
            if i == n:
                break
    elif d == 3:
        for j in range(c):
            cy -= 1
            i += 1
            if i == n:
                break
    else:
        for j in range(c):
            cx -= 1
            i += 1
            if i == n:
                break
    if i == n:
        break
    d += 1
    d %= 4
    if d % 2 == 1:
        c += 1
print(cx, cy)
