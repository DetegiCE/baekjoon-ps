while True:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = []
    for _ in range(10):
        c.append(0)
    for i in a:
        for j in b:
            p = str(i * j)
            for k in p:
                c[ord(k)-48] += 1
    for i in range(10):
        print(c[i], end=' ')
    print()

