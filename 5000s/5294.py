c = []
while True:
    try:
        a, b = input().split()
        c.append([int(b), a])
    except:
        break
c.sort()
n = len(c)
i = 0
while i < n:
    if i == n-1: break
    if c[i+1][0] - c[i][0] <= 2:
        print(c[i][1], c[i+1][1])
        i += 1
    i += 1