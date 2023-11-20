n = int(input())
mx = 0
mxl = []
for i in range(1, n+1):
    c = [n, i]
    while True:
        if c[-2] - c[-1] < 0:
            break
        c.append(c[-2] - c[-1])
    if len(c) > mx:
        mx = len(c)
        mxl = c
print(mx)
print(*mxl)
