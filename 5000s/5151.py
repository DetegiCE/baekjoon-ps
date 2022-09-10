for i in range(int(input())):
    print(f'Data Set {i+1}:')
    n, m, t = map(int,input().split())
    d = [0 for _ in range(n+1)]
    for j in range(m):
        a, b, c = input().split()
        a, b, c = int(a), int(b), float(c)
        if 0 <= t - b < 1000:
            d[a] += c
    Y = 0
    N = 0
    for j in range(n):
        e = input()
        if e == 'Y':
            Y += 1
        else:
            N += 1/(1+(d[j+1]/10000))
    print("%.2f %.2f" % (round(Y, 2), round(N, 2)))
    print()