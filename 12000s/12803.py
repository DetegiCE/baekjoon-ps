for _ in range(int(input())):
    n, q = map(int, input().split())
    d = dict()
    for i in range(1, n//2+1):
        d[i] = n-i+1
        d[n-i+1] = i
    a = [i for i in range(1, n+1)]
    for i in range(q):
        f, g = input().split()
        g = int(g)
        if f == '?':
            print(a[g-1])
        else:
            h = d[g]
            a.remove(h)
            a.remove(g)