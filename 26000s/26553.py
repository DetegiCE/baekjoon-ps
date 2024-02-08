for _ in range(int(input())):
    k, p, x = map(int, input().split())
    mn = 1e18
    for m in range(1, 10000000000):
        cpay = m * x + k / m * p
        if cpay > mn:
            break
        else:
            mn = cpay
    print('{:.3f}'.format(mn))
