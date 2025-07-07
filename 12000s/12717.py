t = int(input())
for tc in range(t):
    print(f'Case #{tc+1}:', end=' ')
    n, a, b, c, d, x0, y0, m = map(int, input().split())
    x = [x0]
    y = [y0]
    X = x0
    Y = y0
    for i in range(1, n):
        X = (a * X + b) % m
        Y = (c * Y + d) % m
        x.append(X)
        y.append(Y)
    cnt = 0
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if (x[i]+x[j]+x[k]) % 3 == 0 and (y[i]+y[j]+y[k]) % 3 == 0:
                    cnt += 1
    print(cnt)