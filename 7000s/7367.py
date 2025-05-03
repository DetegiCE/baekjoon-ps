def fmx(a):
    mx = 0
    for i in a:
        t = i
        while t:
            mx = max(mx, t % 10)
            t //= 10
    return mx

while True:
    n = int(input())
    if n == 0:
        break
    a = list(map(int, input().split()))
    mx = fmx(a)
    g = 0
    for i in range(mx+1, 11):
        b = []
        for j in a:
            b.append(int(str(j), i))
        dif = b[1] - b[0]
        f = 1
        for j in range(2, n):
            if b[j] - b[j-1] == dif:
                f += 1
        if f == n-1:
            print(f'Minimum base = {i}.')
            g = 1
            break
    if g == 0:
        print('No base <= 10 can be found.')